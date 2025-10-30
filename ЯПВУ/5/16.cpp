#include <iostream>
#include <cstdio>
using namespace std;

enum Day {
    // Сопоставление дней недели и чисел
    pon = 1,
    vto = 2,
    sre = 3,
    che = 4,
    pya = 5,
    sub = 6,
    vos = 7
};

const char* getDayName(Day day) {
    // Функция для получения словесного описания ноты
    switch (day) {
        case pon: return "Понедельник";
        case vto: return "Вторник";
        case sre: return "Среда";
        case che: return "Четверг";
        case pya: return "Пятница";
        case sub: return "Суббота";
        case vos: return "Воскресенье";
        default: return "Нет соответствующего дня недели"; 
    }
}

int main() {
    int dayNumber;

    printf("Определение дня недели\n");
    printf("Введите номер дня недели (от 1 до 7): ");

    // Ввод номера
    if (!(cin >> dayNumber)) {
        printf("Ошибка ввода. Пожалуйста, введите целое число.\n");
    }

    // Проверка на корректный диапазон
    if (dayNumber < pon || dayNumber > vos) {
        printf("Номер дня недели %d не соответствует диапазону от 1 до 7.\n", dayNumber);
    } else {
        // Преобразование целого числа в тип enum
        Day selectedNote = static_cast<Day>(dayNumber); 

        const char* dayName = getDayName(selectedNote);

        printf("День недели %d — %s.\n", dayNumber, dayName);
    }
}