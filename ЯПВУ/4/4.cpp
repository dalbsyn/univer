#include<iostream>
using namespace std;

void output_days(){
    printf("Соответствие чисел дням:\n1. Понедельник\n2. Вторник\n3. Среда\n4. Четверг\n5. Пятница\n6. Суббота\n7. Воскресенье\n");
}

int main(){
    int number;
    output_days();
    printf("Введите номер дня: ");
    wcin >> number;
    switch (number)
    {
        case 1:
            printf("Рабочий день");
            break;
        case 2:
            printf("Рабочий день");
            break;
        case 3:
            printf("Рабочий день");
            break;
        case 4:
            printf("Рабочий день");
            break;
        case 5:
            printf("Рабочий день");
            break;
        case 6:
            printf("Суббота");
            break;
        case 7:
            printf("Воскресенье");
            break;
        default:
            printf("Вводите числа в диапазоне от 0 до 7.");
            break;
        }
}