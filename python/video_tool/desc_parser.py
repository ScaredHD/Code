
import tokenizer

t = tokenizer.Tokenizer()
t.tokenize('grammar.md')

print(t.tokens())