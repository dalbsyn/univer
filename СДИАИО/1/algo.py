def process_output(text):
    """Обработка входных данных - полученный string превращает в список, где
    каждый элемент списка - строка (line).

    Принимает string и возвращает список, где каждый элемент - список, который
    состоит из string и количества слов в текущем string.
    """
    splitted_text = text.split('\n')
    line_amount = len(splitted_text)
    line_list = []
    for i in splitted_text:
        line_list.append([i, len(i.split())])
    return line_list

def sort(text, type):
    """Алгоритм сортировки на основе сортировки пузырьком.

    Принимает список string-ов и возвращает уже отсортированный список.
    """
    data = process_output(text)
    allowed_types = ["<", ">"]
    n = len(data)

    if type not in allowed_types:
        return 0
    elif type == "<":
        for i in range(n):
            for j in range(0, n - i - 1):
                """Тут сравниваются количество слов в string.

                Если в текущей итерации количество слов больше, чем следующем, то
                списки меняются друг с другом местами. В этом суть пузырькового
                метода. 
                """
                if data[j][1] < data[j + 1][1]:
                    data[j], data[j + 1] = data[j + 1], data[j]
        return data
    elif type == ">":
        for i in range(n):
            for j in range(0, n - i - 1):
                if data[j][1] > data[j + 1][1]:
                    data[j], data[j + 1] = data[j + 1], data[j]
        return data