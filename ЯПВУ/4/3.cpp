#include<iostream>
using namespace std;

int main(){
    int number;
    printf("Введите номер месяца: ");
    wcin >> number;
    switch (number)
    {
        case 1:
            printf("Январь");
            break;
        case 2:
            printf("Февраль");
            break;
        case 3:
            printf("Март");
            break;
        case 4:
            printf("Апрель");
            break;
        case 5:
            printf("Май");
            break;
        case 6:
            printf("Июнь");
            break;
        case 7:
            printf("Июль");
            break;
        case 8:
            printf("Август");
            break;
        case 9:
            printf("Сентябрь");
            break;
        case 10:
            printf("Октябрь");
            break;
        case 11:
            printf("Ноябрь");
            break;
        case 12:
            printf("Декабрь");
            break;
        default:
            printf("Вводите числа в диапазоне от 1 до 12.");
            break;
    }
}