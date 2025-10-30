#include <iostream>
using namespace std;

int main() {
    int count;
    double number;
    double sum = 0.0;

    // Ошибка, если введено количество меньше одного
    printf("Введите количество чисел последовательности -> ");
    if (!(cin >> count) || count <= 0) {
        printf("Некорректный ввод количества чисел. Программа завершена.\n");
    }

    printf("Вводите последовательность. После ввода каждого числа нажимайте <Enter>\n");

    for (int i = 0; i < count; ++i) {
        printf("-> ");
        // Ввод числа
        if (!(cin >> number)) {
            printf("Ошибка ввода числа. Программа завершена.\n");
        }

        // Сложение чисел
        sum += number;
    }

    // Вычисление среднего арифметического
    double average = sum / count;

    printf("Среднее арифметическое введенной последовательности: %.2f", average);
}