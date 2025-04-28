
class CharStream:
    def __init__(self, path):
        self.f = open(path)
        self.content = self.f.read()
        self.pos = 0

    def advance(self):
        self.pos += 1

    def peek(self):
        return self.content[self.pos]


class State:
    def __init__(self, id, is_final=False):
        self.id: str | int = id
        self.is_final = is_final


StateID = str | int
StateGroup = set[State]
StateIDGroup = set[StateID]


class Transition:
    def __init__(self):
        self.default: StateIDGroup = set()
        self.on_input: dict[str, StateIDGroup] = {}
        self.epsilon: StateIDGroup = set()

    def query(self, input: str) -> StateIDGroup:
        if input == '' or input == 'epsilon' or input == 'ε' or input == 'eps':
            return self.epsilon
        if input == 'default':
            return self.default
        if input in self.on_input:
            return self.on_input[input]
        return set()


class NFA:
    def __init__(self, states: StateGroup = set()):
        self.states: dict[StateID, State] = {s.id: s for s in states}
        self.transitions: dict[StateID, Transition] = {
            s.id: Transition() for s in states}
        self.start = None

    def set_start(self, id):
        self.start = id

    def set_finals(self, ids: StateIDGroup):
        for id in ids:
            if id not in self.states:
                raise Exception(f'State ID: {id} not exists')
            self.states[id].is_final = True

    def final_states(self) -> StateIDGroup:
        return {s.id for s in self.states.values() if s.is_final}

    def contains_state(self, id):
        return id in self.states

    def check_state_presence(self, state):
        if not self.contains_state(state):
            raise Exception(f'State ID: {state} not exists')

    def add_states(self, states: StateGroup):
        for s in states:
            if s.id in self.states:
                raise Exception(f'id: {s.id} already exists')

            self.states[s.id] = s
            self.transitions[s.id] = Transition()

    def add_transition(self, from_ids: StateIDGroup | StateID, input: str, to_ids: StateIDGroup | StateID):
        from_set = set()
        if type(from_ids) is str or type(from_ids) is int:
            from_set = {from_ids}
        else:
            from_set = from_ids
        
        to_set = set()
        if type(to_ids) is str or type(to_ids) is int:
            to_set = {to_ids}
        else:
            to_set = to_ids

        for from_id in from_set:
            self.check_state_presence(from_id)
        for to_id in to_set:
            self.check_state_presence(to_id)

        for from_id in from_set:
            t = self.transitions[from_id]
            if input == '' or input == 'epsilon' or input == 'ε' or input == 'eps':
                t.epsilon = t.epsilon.union(to_set)
            elif input == 'default':
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


class Tokenizer:
    def __init__(self):
        self.token_list = []

    def tokens(self):
        return self.token_list

    def tokenize(self, file_or_cs):
        if type(file_or_cs) == type(''):
            file = file_or_cs
            cs = CharStream(file)
            self.tokenize(cs)
            return

        if type(file_or_cs) == CharStream:
            cs = file_or_cs
            self.do_tokenize(cs)

    def do_tokenize(self, cs: CharStream):
        return []
