
import tokenizer as tk

machine = tk.NFA()

machine.add_states({tk.State(0), tk.State(1),
                   tk.State(2), tk.State(3, True)})

machine.add_transition(0, 'c', 1)

machine.set_start(0)

machine.validate()
