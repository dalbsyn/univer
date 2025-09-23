def process_output(text):
    """Обработка входных данных - полученный string превращает в список, где
    каждый элемент списка - строка (line).

    Принимает string и возвращает список, где каждый элемент - список, который
    состоит из string и количества слов в текущем string.
    """
    splitted_text = text.split(' ')
    line_list = []
    for i in splitted_text:
        try:
            line_list.append(int(i))
        except ValueError:
            return 0
    return line_list

def find_all_increasing_subsequences(arr):
    """
    Поиск и сохранение всех подпоследовательностей.
    """
    subsequences = []
    
    """
    Генератор подпоследовательностей на основе рекурсивной функции.
    Если текущая подпоследовательность увеличивается, то начинается следующая итерация.
    Если не увеличивается, то эта подпоследовательность сохраняется.
    """
    def generate_subsequences(current_seq, remaining_arr):
        if not remaining_arr:
            # Check if the generated subsequence is increasing
            is_increasing = True
            for i in range(1, len(current_seq)):
                if current_seq[i] <= current_seq[i-1]:
                    is_increasing = False
                    break
            
            if is_increasing and len(current_seq) > 0:
                subsequences.append(current_seq)
            return

        # Включить текущий элемент
        generate_subsequences(current_seq + [remaining_arr[0]], remaining_arr[1:])
        # Исключить текущий элемент
        generate_subsequences(current_seq, remaining_arr[1:])
    
    generate_subsequences([], arr)
    return subsequences

def find_longest_increasing_subsequence(arr):
    """
    Поиск наибольшей возрастающей подпоследовательности (нвп).
    """
    if not arr:
        return []

    n = len(arr)
    dp = [1] * n  # список количества элементов всех подпоследовательностей
    prev_index = [-1] * n  # вспомогательный список для бектрекинга, где каждый элемент - указатель к прошлому элементу (поэтому -1), подобие флагового значения.

    """
    Если текущий элемент подпоследовательности больше, чем предыдущий, то это 
    засчитывается в количество чисел текущей подпоследовательности.
    """
    for i in range(1, n):
        for j in range(i):
            if arr[i] > arr[j] and dp[j] + 1 > dp[i]:
                dp[i] = dp[j] + 1
                prev_index[i] = j

    # Поиск индекса нвп
    max_length = 0
    end_index = -1
    for i in range(n):
        if dp[i] > max_length:
            max_length = dp[i]
            end_index = i

    """
    Реконструкция нвп с помощью бектрекинга.
    Сперва находится число нвп, от которого идем обратно к началу последовательности, пока не достигнем флагового значения
    """
    lis = []
    if end_index != -1:
        current_index = end_index
        while current_index != -1:
            lis.insert(0, arr[current_index])
            current_index = prev_index[current_index]

    return lis