
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


class Transition:
    def __init__(self, *, default_to_state=None, on_input_dict={}):
        self.default: str | int = default_to_state
        self.on_input: dict[str, set[str | int]] = on_input_dict


class NFA:
    def __init__(self, states: set[State] = set()):
        self.states: dict[int | str, State] = {s.id: s for s in states}
        self.transition: dict[int | str, Transition] = {
            s.id: Transition() for s in states}
        self.start = None

    def set_start(self, id):
        self.start = id

    def contains_state(self, id):
        return id in self.states

    def check_state_presence(self, state):
        if not self.contains_state(state):
            raise Exception(f'State ID: {state} not exists')

    def add_states(self, states: set[State]):
        for s in states:
            if s.id in self.states:
                raise Exception(f'id: {s.id} already exists')

            self.states[s.id] = s
            self.transition[s.id] = Transition()

    def set_default_transition(self, from_id, to_id):
        self.check_state_presence(from_id)
        self.check_state_presence(to_id)
        t = self.transition[from_id]
        t.default = to_id

    def add_transition(self, from_id, input, to_id):
        self.check_state_presence(from_id)
        self.check_state_presence(to_id)
        t = self.transition[from_id]
        if input in t.on_input:
            t.on_input[input].add(to_id)
        else:
            t.on_input[input] = {to_id}

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
    def __init__(self):
        self.nfa = NFA()
        self.state_group_track = []
        self.input_track = []

    def move(self, input) -> set[State]:
        pass


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
