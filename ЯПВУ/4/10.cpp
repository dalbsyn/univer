#include <iostream>
#include <string>
#include <algorithm> // Для std::to_string

std::string ones(int n) {
    // Единицы в греческую форму
    switch (n) {
        case 0: return "miden";
        case 1: return "ena";
        case 2: return "dio";
        case 3: return "tria";
        case 4: return "tessera";
        case 5: return "pente";
        case 6: return "exi";
        case 7: return "efta";
        case 8: return "okto";
        case 9: return "ennia";
        default: return "";
    }
}

std::string teens_and_tens(int n) {
    if (n >= 10 && n <= 19) {
        // Числа от 10 до 19
        switch (n) {
            case 10: return "deka";
            case 11: return "enteka";
            case 12: return "dodeka";
            case 13: return "dekatria";
            case 14: return "dekatessera";
            case 15: return "dekapente";
            case 16: return "dekaexi";
            case 17: return "dekefta";
            case 18: return "dekaokto";
            case 19: return "dekaennia";
        }
    } else {
        // Десятки
        int tens_digit = n / 10;
        switch (tens_digit) {
            case 2: return "eikosi";
            case 3: return "trianta";
            case 4: return "saranta";
            case 5: return "peninta";
            case 6: return "exinta";
            case 7: return "evdominta";
            case 8: return "ogdonta";
            case 9: return "eneninta";
        }
    }
    return "";
}

std::string hundreds(int n) {
    // Сотни в греческую форму
    int h_digit = n / 100;
    switch (h_digit) {
        case 1: return "ekato";
        case 2: return "diakosia";
        case 3: return "triakosia";
        case 4: return "tetrakosia";
        case 5: return "pentakosia";
        case 6: return "exakosia";
        case 7: return "eptakosia";
        case 8: return "oktakosia";
        case 9: return "ennakosia";
        default: return "";
    }
}


std::string numberToGreek(int num) {
    // Сама функция перевода числа в словесную форму
    if (num < 0 || num > 999) {
        return "Число вне диапазона (0-999)";
    }
    if (num == 0) {
        return ones(0);
    }

    std::string result = "";
    int h = num / 100;
    int t = num % 100;

    // Сотни
    if (h > 0) {
        if (h == 1) {
            // Особенность греческого: 100 = "ekato", но "101" = "ekaton ena"
            if (t > 0) {
                result += "ekaton"; // "ekaton" (с 'n') для чисел > 100
            } else {
                result += "ekato";  // "ekato" (без 'n') для 100
            }
        } else {
            result += hundreds(h * 100);
        }
        
        if (t > 0) {
            result += " ";
        }
    }

    // Десятки и единицы
    if (t > 0) {
        if (t >= 10 && t <= 19) {
            // Числа от 10 до 19
            result += teens_and_tens(t);
        } else {
            // Десятки (20, 30, ...)
            int ten_part = t / 10;
            int one_part = t % 10;
            
            if (ten_part > 0) {
                result += teens_and_tens(ten_part * 10);
            }
            
            // Соединение десятков и единиц
            if (ten_part > 0 && one_part > 0) {
                result += " ";
            }
            
            // Единицы
            if (one_part > 0) {
                result += ones(one_part);
            }
        }
    }

    return result;
}

int main() {
    setlocale(LC_ALL, "");
    int number;
    printf("Введите число (0-999): ");
    
    if (!(std::cin >> number)) {
        printf("Ошибка ввода числа.");
    }

    std::string greek_form = numberToGreek(number);
    std::wcout << greek_form;
    printf("Число %d в греческой словесной форме: %s.", number, greek_form);
}