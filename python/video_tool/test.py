
import tokenizer as tk

machine = tk.NFA()

machine.add_states({tk.State(i) for i in range(9)})
machine.set_start(0)
machine.set_finals({2, 6, 8})

machine.add_transitions([
    (0, 'eps', {1, 3, 7}),
    (1, 'a', 2),
    (7, 'a', 7),
    (7, 'b', 8),
    (8, 'b', 8),
    (3, 'a', 4),
    (4, 'b', 5),
    (5, 'b', 6)
])


simulation = tk.NFASimulation(machine)

simulation.process_input('a')
print(simulation.state_group_track)
simulation.process_input('a')
print(simulation.state_group_track)
simulation.process_input('b')
print(simulation.state_group_track)
simulation.process_input('a')
print(simulation.state_group_track)

machine.validate()
