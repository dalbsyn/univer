#include<iostream>
using namespace std;

int main(){
    int number;
    printf("Введите трехзначное число: ");
    wcin >> number;
    if (number > 99 & number < 1000){
        int digit1 = number / 100;
        int digit2 = (number / 10) % 10;
        int digit3 = number % 10;
        int result = digit1 + digit2 +  digit3;

        if (result > 9 && result < 100){
            printf("Сумма цифр числа %d (%d, %d, %d): %d.", number, digit1, digit2, digit3, result);
        }
        else {
            printf("Сумма цифр числа %d (%d, %d, %d = %d) не является двузначным.", number, digit1, digit2, digit3, result);
        }
    } else {
        printf("Введено не трехзначное число.");
    }
}