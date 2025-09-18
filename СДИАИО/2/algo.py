def process_input(input: str):
    input = input
    output = []
    print(input)
    processed_input = input.split(' ')
    print(processed_input)
    for i in processed_input:
        try:
            output.append(int(i))
        except ValueError:
            return 0
    return output

def sort(input):
    input = process_input(input)
    processed_input = []
    if input == 0:
        return 0
    else:
        for i in range(len(input)):
            for j in range(i + 1, len(input)):
                if input[i] < input[j]:
                    print(f'{input[i]} < {input[j]}')
                    processed_input.append(input[i])
    return processed_input