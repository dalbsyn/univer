#include<iostream>
using namespace std;

int main(){
    // Дан год. Вывести на экран название животного, символизирующего этот год по восточному календарю
    int year;
    printf("Введите год: ");
    wcin >> year;
    int result = (year - 1900) % 12;
    switch (result){
        case 0:
            printf("КРЫСА");
            break;
        case 1:
            printf("БЫК");
            break;
        case 2:
            printf("ТИГР");
            break;
        case 3:
            printf("Кролик");
            break;
        case 4:
            printf("Дракон");
            break;
        case 5:
            printf("Змея");
            break;
        case 6:
            printf("Лошадь");
            break;
        case 7:
            printf("Коза");
            break;
        case 8:
            printf("Обезьяна");
            break;
        case 9:
            printf("Петух");
            break;
        case 10:
            printf("Собака");
            break;
        case 11:
            printf("КАБАН");
            break;
    }
}