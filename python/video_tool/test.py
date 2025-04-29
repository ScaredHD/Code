
import tokenizer as tk

t = tk.Tokenizer()
t.tokenize('test.txt')
print(t.token_list)
print('\n')
print([token for i, token in enumerate(t.token_list) if type(
    t.transformed_token_list[i]) is not tk.TokenWhitespace])

pass
