import re

def check(text):
    regex = re.compile("[a-zA-Z]").findall(text)
    word = "".join(regex)
    print(f"""====
Введенное слово: {text}.
Полученное слово после проверки соответствия: {word}.
====""")
    return word

def cyr(text):
    regex_cyr = re.compile("[а-яА-Я]").findall(text)
    # print(regex_cyr)
    return regex_cyr

def num(text):
    regex_num = re.compile("[\\d]").findall(text)
    # print(regex_num)
    return regex_num

def char(text):
    regex_char = re.compile("[\\W]").findall(text)
    # print(regex_char)
    return regex_char

def form_errors(text):
    validations = [cyr(text), num(text), char(text)]
    for i in validations:
        if i != []:
            errors.append(i)

if __name__ == '__main__':
    errors = []
    text = input("""====
ВВЕДИТЕ ТЕКСТ, УДОВЛЕТВОРЯЮЩИЙ СЛЕДУЮЩИМ УСЛОВИЯМ:
- НЕ СОДЕРЖИТ ЦИФРЫ;
- НЕ СОДЕРЖИТ КАКИЕ-ЛИБО СИМВОЛЫ, ВРОДЕ ЭТИХ: пробел, . / {} и т.п.
- ТОЛЬКО ЛАТИНСКИЕ БУКВЫ.
ПОЛЕ ВВОДА ТЕКСТА: """)

    if check(text) != text:
        form_errors(text)
        print('Выявлены следующие несоответствия:')
        for i in errors:
            print(i)
    else:
        print("Несоответствий не обнаружено.")
