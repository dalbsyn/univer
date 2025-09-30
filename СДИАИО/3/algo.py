import re

def reverse_output_file(filepath):
    word_list = []
    reversed_words = []

    try:
        with open(filepath, 'r') as file:
            text_content = file.read()
            words = re.split(r'(\s+)', text_content)
            for word in words:
                word_list.append(word)
        
        while word_list:
            reversed_words.append(word_list.pop())
        
        return reversed_words
    
    except UnicodeDecodeError:
        return 0
    
    except FileNotFoundError:
        return 0

def output(words):
    final_string = "".join(words)
    return final_string