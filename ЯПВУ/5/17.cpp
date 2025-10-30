#include <iostream>
using namespace std;

enum Velo {
    // Сопоставление велосипедов и чисел
    scott = 1,
    giant = 2,
    aspect = 3,
    stinger = 4,
    stels = 5,
    format = 6,
    atom = 7,
    welt = 8,
    polygon = 9,
    stark = 10
};

const char* getNoteName(Velo velo) {
    // Функция для получения словесного описания велосипеда
    switch (velo) {
        case stark: return "Stark";
        case scott: return "Scott";
        case aspect: return "Aspect";
        case stels: return "Stels";
        case stinger: return "Stinger";
        case format: return "Format";
        case atom: return "Atom";
        case welt: return "Welt";
        case polygon: return "Polygon";
        case giant: return "Giant";
        default: return "Неизвестный производитель"; 
    }
}

int main() {
    int velonum;

    printf("Определение производителя велосипедов\n");
    printf("Введите номер производителя (от 1 до 10): ");

    // Ввод номера
    if (!(cin >> velonum)) {
        printf("Ошибка ввода. Пожалуйста, введите целое число.\n");
    }

    // Проверка на корректный диапазон
    if (velonum < scott || velonum > stark) {
        printf("Номер производителя %d не соответствует диапазону от 1 до 10.\n", velonum);
    } else {
        // Преобразование целого числа в тип enum
        Velo selectedVelo = static_cast<Velo>(velonum); 

        const char* veloname = getNoteName(selectedVelo);

        printf("Велосипед %d — %s.\n", velonum, veloname);
    }
}