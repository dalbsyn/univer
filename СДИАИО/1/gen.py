import random
import argparse

"""Простой генератор строк

Принимает аргументы командной строки:
- --lines (-l) - количество генерируемых строк;
- --count (-m) - максимальное количество слов, которое может находиться в 
строке.
"""
# Алфавит допустимых букв
SYMBOLS = 'абвгдеёжзийклмнопрстуфхцчшщъыьэюя'

def generate_word():
    """Генерация слова
    """
    word_length = random.randint(2, 4)
    return ''.join(random.choices(SYMBOLS, k=word_length))

def generate_text(num_lines: int, max_words_per_line: int):
    """Генерация текста
    """
    for _ in range(num_lines):
        num_words = random.randint(1, max_words_per_line)
        line = [generate_word() for _ in range(num_words)]
        print(' '.join(line))

# Инициализация парсера аргументов командной строки
parser = argparse.ArgumentParser(prog='gen')
parser.add_argument('-l', '--lines')
parser.add_argument('-m', '--max')
args = parser.parse_args()
lines_to_generate = int(args.lines)
max_words = int(args.max)

generate_text(lines_to_generate, max_words)