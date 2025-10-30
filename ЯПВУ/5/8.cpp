#include <iostream>
#include <cstdlib> // rand
using namespace std;

int main() {
    int sequence_length = 10; // количество чисел в последовательности
    int sequence_num = 3; // количество последовательностей

    printf("*** Случайные числа ***\n");

    // Генерация трех последовательностей
    for (int seq = 0; seq < sequence_num; ++seq) {
        double sum = 0.0; // Сумма чисел для текущей последовательности
        int randnum;

        // Генерация 10 чисел в текущей последовательности
        for (int i = 0; i < sequence_length; ++i) {
            // Генерация случайного числа в диапазоне [1, 10]
            // rand() % 10 дает числа от 0 до 9. Добавляем 1, чтобы получить [1, 10].
            randnum = (rand() % 10) + 1;
            
            // Вывод числа и пробела
            printf("%d ", randnum);
            
            // Накопление суммы
            sum += randnum;
        }

        // Вычисление среднего арифметического
        double average = sum / sequence_length;

        // Вывод среднего арифметического с форматированием (два знака после запятой)
        printf("сред. арифм. %.2f\n", average);
    }

    return 0;
}