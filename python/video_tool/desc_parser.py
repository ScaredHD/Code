
import tokenizer as tk


class DescParser:
    def __init__(self):
        self.tokenizer = tk.Tokenizer()
        self.ignore_whitespce = True
        self.next = 0

    def parse(self, file):
        self.tokenizer.tokenize(file)
        self.do_parse()

    def next_token_ns(self):
        token = self.next_token()
        while type(token) is tk.TokenWhitespace:
            token = self.next_token()
        return token

    def next_token(self):
        token = self.tokenizer.transformed_token_list[next]
        self.next += 1
        return token

    def do_parse(self):
        pass
