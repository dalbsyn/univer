import re

def check(text):
    regex = re.compile("[a-zA-Z]").findall(text)
    word = "".join(regex)
    print(f"""====
Введенное слово: {text}.
Полученное слово после проверки соответствия: {word}.
====""")
    return word

def collect_errors(text):
    regex_cyr = re.compile("[а-яА-Я]").findall(text)
    regex_num = re.compile("[\\d]").findall(text)
    regex_char = re.compile("[\\W]").findall(text)
    if regex_cyr:
        errors.append(f"Причина несоответствия в наличии не латинских символов: {regex_cyr}.")
    if regex_num:
        errors.append(f"Причина несоответствия в наличии цифр: {regex_num}.")
    if regex_char:
       errors.append(f"Причина несоответствия в наличии других символов: {regex_char}.")
    if regex_char or regex_num or regex_char:
        errors.append(f"Строка не соответствует условию")
        
def output_errors():
    for i in errors:
        print(i)

errors = []
text = input("""====
ВВЕДИТЕ ТЕКСТ, УДОВЛЕТВОРЯЮЩИЙ СЛЕДУЮЩИМ УСЛОВИЯМ:
- НЕ СОДЕРЖИТ ЦИФРЫ;
- НЕ СОДЕРЖИТ КАКИЕ-ЛИБО СИМВОЛЫ, ВРОДЕ ЭТИХ: пробел, . / {} и т.п.
- ТОЛЬКО ЛАТИНСКИЕ БУКВЫ.
ПОЛЕ ВВОДА ТЕКСТА: """)

if check(text) != text:
    collect_errors(text)
    output_errors()
else:
    print("Несоответствий не обнаружено.")
