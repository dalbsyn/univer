import re

class Stack():
    def __init__(self):
        self.stack = []
    
    def push(self, item):
        self.stack.append(item)
    
    def pop(self):
        return self.stack.pop()
    

def reverse_output_file(filepath):
    word_list = Stack()
    reversed_words = Stack()
    try:
        with open(filepath, 'r') as file:
            text_content = file.read()
            words = re.split(r'(\s+)', text_content)
            for word in words:
                word_list.push(word)
        
        while word_list.stack:
            reversed_words.push(word_list.pop())

    except (UnicodeDecodeError, FileNotFoundError):
        return 400
    
    return reversed_words.stack
    
def output(words):
    final_string = "".join(words)
    return final_string

def get_text(filepath):
    with open(filepath, 'r') as file:
        try:
            return file.read()
        except (UnicodeDecodeError, FileNotFoundError):
            return 400