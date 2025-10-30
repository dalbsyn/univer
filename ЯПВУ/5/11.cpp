#include <iostream>
using namespace std;

int main() {
    // Начальное и конечное значение аргумента X
    double start_x = -4.0;
    double end_x = 4.0;
    // Шаг изменения аргумента
    double step = 0.5;

    double x; // Аргумент
    double y; // Значение функции

    // Вывод заголовка таблицы с помощью printf
    printf("x\ty = 2x^2-5x-8\n");

    // Цикл for для перебора значений x
    for (x = start_x; x <= end_x + (step / 2.0); x += step) {
        
        // Вычисление значения функции
        y = 2.0 * x * x - 5.0 * x - 8.0;

        printf("%.1f\t%.2f\n", x, y);
    }
}