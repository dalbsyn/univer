#include <iostream>
#include <cstdio>
using namespace std;

enum Note {
    // Сопоставление нот и чисел
    DO = 1,
    RE = 2,
    MI = 3,
    FA = 4,
    SOL = 5,
    LA = 6,
    SI = 7
};

const char* getNoteName(Note note) {
    // Функция для получения словесного описания ноты
    switch (note) {
        case DO: return "до";
        case RE: return "ре";
        case MI: return "ми";
        case FA: return "фа";
        case SOL: return "соль";
        case LA: return "ля";
        case SI: return "си";
        default: return "неизвестная нота"; 
    }
}

int main() {
    int noteNumber;

    printf("Определение музыкальной ноты\n");
    printf("Введите номер ноты (от 1 до 7): ");

    // Ввод номера
    if (!(cin >> noteNumber)) {
        printf("Ошибка ввода. Пожалуйста, введите целое число.\n");
    }

    // Проверка на корректный диапазон
    if (noteNumber < DO || noteNumber > SI) {
        printf("Номер ноты %d не соответствует музыкальному диапазону от 1 до 7.\n", noteNumber);
    } else {
        // Преобразование целого числа в тип enum
        Note selectedNote = static_cast<Note>(noteNumber); 

        const char* noteName = getNoteName(selectedNote);

        printf("Нота %d — %s.\n", noteNumber, noteName);
    }
}