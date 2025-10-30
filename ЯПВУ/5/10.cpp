#include <iostream>
#include <cstdlib> // rand(), srand()
#include <ctime>   // time()
using namespace std;

int main() {
    int max_att = 5;
    
    // Инициализация генератора случайных чисел с сидом времени, который
    // генерирует действительно случайное число
    srand(time(0));

    // Задуманное число (в диапазоне от 1 до 10)
    int secretNumber = (rand() % 10) + 1;
    
    int guess; // Вводимое число
    bool win = false; // Флаг победы

    // Вывод начальных инструкций
    printf("Игра \"Угадай число\".\n");
    printf("Компьютер \"задумал\" число от 1 до 10.\n");
    printf("Угадайте его за %d попыток.\n", max_att);
    printf("Введите число и нажмите <Enter>\n");

    // Цикл ввода чисел пользователем
    for (int attempt = 1; attempt <= max_att; ++attempt) {
        printf("-> ");

        // Ввод числа
        if (!(cin >> guess)) {
            // Обработка ошибки ввода
            printf("Ошибка ввода. Пожалуйста, введите число.\n");
            continue; 
        }

        // Проверка числа
        if (guess == secretNumber) {
            win = true;
            printf("Вы выиграли! Поздравляю!\n");
            break; 
        } else {
            printf("Нет.\n"); 
        }
    }

    // Если попытки исчерпаны
    if (!win) {
        printf("\n");
        printf("Вы проиграли. Задуманное число было %d.\n", secretNumber);
    }

    return 0;
}