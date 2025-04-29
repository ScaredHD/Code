import string


class CharStream:
    def __init__(self, path):
        self.f = open(path)
        self.content = self.f.read()
        self.len = len(self.content)

    def advance(self):
        self.pos += 1

    def peek(self):
        return self.content[self.pos]

    def substring(self, start, end):
        return self.content[start:end]


class State:
    def __init__(self, id, is_final=False):
        self.id: str | int = id
        self.is_final = is_final
        self.token_type = None


StateID = str | int
StateGroup = set[State]
StateIDGroup = set[StateID]

charset_printable = set(string.printable)
charset_ws = {' ', '\t', '\n'}
charset_newline = {'\n'}
charset_special_symbols = {':', '[', ']', '"'}
charset_quoted_string_delimiter = {'"'}
charset_quoted_string_content = charset_printable - \
    charset_newline - charset_quoted_string_delimiter
charset_ns = charset_printable - charset_ws
charset_digits = set(string.digits)
charset_letters = set(string.ascii_letters)
charset_simple_string = charset_letters | charset_digits | {'_'}


def is_epsilon(input: str):
    return input == '' or input == 'epsilon' or input == 'eps'


def is_default(input: str):
    return input == 'default' or input == 'other'


class Transition:
    def __init__(self):
        self.default: StateIDGroup = set()
        self.on_input: dict[str, StateIDGroup] = {}
        self.epsilon: StateIDGroup = set()

    def query(self, input: str) -> StateIDGroup:
        if is_epsilon(input):
            return self.epsilon
        if is_default(input):
            return self.default
        if input in self.on_input:
            return self.on_input[input]
        return self.default


class NFA:
    def __init__(self):
        self.states: dict[StateID, State] = dict()
        self.transitions: dict[StateID, Transition] = dict()
        self.start = None

    def set_start(self, id):
        self.start = id

    def set_finals(self, ids: StateIDGroup, token_type):
        for id in ids:
            if id not in self.states:
                raise Exception(f'State ID: {id} not exists')
            self.states[id].is_final = True
            self.states[id].token_type = token_type

    def final_states(self) -> StateIDGroup:
        return {s.id for s in self.states.values() if s.is_final}

    def contains_state(self, id):
        return id in self.states

    def check_state_presence(self, state):
        if not self.contains_state(state):
            raise Exception(f'State ID: {state} not exists')

    def create_states(self, state_ids: StateIDGroup):
        self.states = {s_id: State(s_id) for s_id in state_ids}
        self.transitions: dict[StateID, Transition] = {
            s: Transition() for s in state_ids}
        self.start = None

    def add_states(self, states: StateGroup):
        for s in states:
            if s.id in self.states:
                raise Exception(f'id: {s.id} already exists')

            self.states[s.id] = s
            self.transitions[s.id] = Transition()

    def add_transition(self, from_ids: StateIDGroup | StateID, inputs: set[str] | str, to_ids: StateIDGroup | StateID):
        from_set = set()
        if type(from_ids) is str or type(from_ids) is int:
            from_set = {from_ids}
        else:
            from_set = from_ids

        for from_id in from_set:
            self.check_state_presence(from_id)

        to_set = set()
        if type(to_ids) is str or type(to_ids) is int:
            to_set = {to_ids}
        else:
            to_set = to_ids

        for to_id in to_set:
            self.check_state_presence(to_id)

        input_set = set()
        if type(inputs) is str:
            input_set.add(inputs)
        else:
            input_set = inputs

        for from_id in from_set:
            for input in input_set:
                t = self.transitions[from_id]
                if is_epsilon(input):
                    t.epsilon = t.epsilon.union(to_set)
                elif is_default(input):
                    t.default = t.default.union(to_set)
                elif input in t.on_input:
                    t.on_input[input] = t.on_input[input].union(to_set)
                else:
                    t.on_input[input] = to_set

    def add_transitions(self, transition_list: list[tuple]):
        for from_ids, input, to_ids in transition_list:
            self.add_transition(from_ids, input, to_ids)

    def validate(self):
        if self.start is None:
            raise Exception('There must be a start state')

        exist_final = False
        for _, s in self.states.items():
            exist_final = exist_final or s.is_final
            if exist_final:
                break

        if not exist_final:
            raise Exception('There must be at least one final state')


class NFASimulation:
    def __init__(self, nfa: NFA):
        self.nfa = nfa
        self.reset()

    def reset(self):
        self.state_group_track = [self.epsilon_closure({self.nfa.start})]
        self.input_track = ['start']

    def query_move(self, state_ids: StateIDGroup, input: str) -> StateIDGroup:
        assert state_ids & self.nfa.states.keys(
        ) == state_ids, 'state_ids contains invalid state id(s)'

        res = set()
        for state_id in state_ids:
            t = self.nfa.transitions[state_id]
            to_states = t.query(input)
            res = res.union(to_states)

        return res

    def process_input(self, input: str) -> StateIDGroup:
        assert len(self.state_group_track) == len(
            self.input_track), 'state_group_track and input_track must be same length'
        current_states = self.state_group_track[-1]
        states = self.query_move(current_states, input)
        states = self.epsilon_closure(states)
        self.state_group_track.append(states)
        self.input_track.append(input)

    def epsilon_closure(self, state_ids: StateIDGroup) -> StateIDGroup:
        assert state_ids & self.nfa.states.keys(
        ) == state_ids, 'state_ids contains invalid state id(s)'

        before = set()
        after = state_ids
        while before != after:
            before = after
            after = self.query_move(before, 'epsilon') | state_ids

        return after

    def has_terminated(self) -> bool:
        return self.state_group_track[-1] == set()


class TokenNumber:
    def __init__(self, token: str):
        self.raw_str = token
        self.value = float(token)


def nfa_number():
    nfa = NFA()
    nfa.create_states({'num0', 'num1', 'num2', 'num3'})
    nfa.set_finals({'num1', 'num3'}, TokenNumber)
    nfa.set_start('num0')
    nfa.add_transitions([
        ('num0', charset_digits, 'num1'),
        ('num1', charset_digits, 'num1'),
        ('num1', '.', 'num2'),
        ('num2', charset_digits, 'num3'),
        ('num3', charset_digits, 'num3')
    ])
    return nfa


class TokenSimpleString:
    def __init__(self, token: str):
        self.raw_str = token

def nfa_simple_string():
    nfa = NFA()
    nfa.create_states({'str0', 'str1'})
    nfa.set_finals({'str1'}, TokenSimpleString)
    nfa.set_start('str0')
    nfa.add_transitions([
        ('str0', charset_simple_string, 'str1'),
        ('str1', charset_simple_string, 'str1')
    ])
    return nfa

class TokenQuotedString:
    def __init__(self, token: str):
        self.raw_str = token
        self.value = token[1:-1]  # remove the quotes


def nfa_quoted_string():
    nfa = NFA()
    nfa.create_states({'qstr0', 'qstr1', 'qstr2'})
    nfa.set_finals({'qstr2'}, TokenQuotedString)
    nfa.set_start('qstr0')
    nfa.add_transitions([
        ('qstr0', '"', 'qstr1'),
        ('qstr1', charset_quoted_string_content, 'qstr1'),
        ('qstr1', '"', 'qstr2')
    ])
    return nfa


class TokenWhitespace:
    def __init__(self, token: str):
        self.raw_str = token
        self.newline_count = token.count('\n')


def nfa_whitespace():
    nfa = NFA()
    nfa.create_states({'ws0', 'ws1'})
    nfa.set_finals({'ws1'}, TokenWhitespace)
    nfa.set_start('ws0')
    nfa.add_transitions([('ws0', charset_ws, 'ws1'),
                        ('ws1', charset_ws, 'ws1')])
    return nfa


class TokenColon:
    def __init__(self, token: str):
        self.raw_str = token


class TokenOpenBracket():
    def __init__(self, token: str):
        self.raw_str = token


class TokenCloseBracket():
    def __init__(self, token: str):
        self.raw_str = token

class TokenArrow():
    pass

def nfa_special_symbols():
    nfa = NFA()
    nfa.create_states({'symbol_start', 'colon',
                      'lbracket', 'rbracket'})
    nfa.set_finals({'colon'}, TokenColon)
    nfa.set_finals({'lbracket'}, TokenOpenBracket)
    nfa.set_finals({'rbracket'}, TokenCloseBracket)
    nfa.set_start('symbol_start')
    nfa.add_transition('symbol_start', ':', 'colon')
    nfa.add_transition('symbol_start', '[', 'lbracket')
    nfa.add_transition('symbol_start', ']', 'rbracket')
    return nfa


def combine_nfa(nfa0: NFA, nfa1: NFA, new_start: StateID):
    states0 = nfa0.states
    states1 = nfa1.states
    combined_states = states0 | states1

    assert len(
        combined_states) > 0, "There must be at least one state in the combined NFA"
    assert len(combined_states) == len(states0) + \
        len(states1), "There exist states with same id's"

    res = NFA()
    res.states = combined_states
    res.transitions = nfa0.transitions | nfa1.transitions
    res.start = new_start

    return res


def create_tokenizer_nfa(nfa_list: list[NFA]):
    nfa = NFA()
    nfa.create_states({'token_start'})
    for nfa_i in nfa_list:
        nfa = combine_nfa(nfa, nfa_i, 'token_start')
        nfa.add_transition('token_start', 'epsilon', nfa_i.start)
    return nfa


class Tokenizer:
    def __init__(self):
        self.token_list = []
        self.transformed_token_list = []
        self.token_actions = []
        self.lexeme_begin = 0
        self.forward = 0
        self.cs = None
        self.reached_eof = False
        self.current_linenumber = 1

    def tokens(self):
        return self.token_list

    def accept(self, token_type):
        token = self.cs.substring(self.lexeme_begin, self.forward)
        self.token_list.append(token)
        self.transformed_token_list.append(token_type(token))
        self.lexeme_begin = self.forward
        if type(self.transformed_token_list[-1]) is TokenWhitespace:
            self.current_linenumber += self.transformed_token_list[-1].newline_count

    def tokenize(self, file_or_cs):
        if type(file_or_cs) == type(''):
            file = file_or_cs
            self.cs = CharStream(file)
            self.tokenize(self.cs)
        elif type(file_or_cs) == CharStream:
            self.cs = file_or_cs
            self.do_tokenize()

    def do_tokenize(self):
        tokenizer_nfa = create_tokenizer_nfa([
            nfa_number(),
            nfa_quoted_string(),
            nfa_simple_string(),
            nfa_whitespace(),
            nfa_special_symbols()
        ])
        tokenizer_nfa.validate()

        simulation = NFASimulation(tokenizer_nfa)
        final_states = simulation.nfa.final_states()

        while self.lexeme_begin < self.cs.len:
            input = self.cs.content[self.forward]
            simulation.process_input(input)
            self.forward += 1

            if self.forward >= self.cs.len:
                self.reached_eof = True

            if self.reached_eof or simulation.has_terminated():
                origin_forward = self.forward
                has_accepted = False
                while self.forward > self.lexeme_begin:
                    states = simulation.state_group_track[-1]
                    accept_states = states & final_states
                    if accept_states != set():
                        accept_state_id = list(accept_states)[0]
                        accept_state = simulation.nfa.states[accept_state_id]
                        token_type = accept_state.token_type
                        self.accept(token_type)
                        simulation.reset()
                        has_accepted = True
                        break

                    simulation.state_group_track.pop()
                    simulation.input_track.pop()
                    self.forward -= 1

                if not has_accepted and self.forward == self.lexeme_begin:
                    cur_ln = self.current_linenumber
                    cur_str = self.cs.substring(
                        self.lexeme_begin, origin_forward)
                    raise Exception(
                        f'No valid token found at line {cur_ln}: {cur_str}')

        return self.token_list
