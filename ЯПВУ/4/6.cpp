#include<iostream>
using namespace std;

int main(){
    int number;
    printf("Введите число: ");
    wcin >> number;
    if (number >= 99 && number < 1000){
        int digit1 = number / 100; // Сотни
        int digit2 = (number / 10) % 10; // Десятки
        int digit3 = number % 10; // Единица

        if (digit1 == digit2 || digit2 == digit3 || digit1 == digit3){
            printf("Число трехзначное, но какие-то содержащие цифры одинаковые: %d, %d, %d.", digit1, digit2, digit3);
        } else {
            printf("Число трехзначное и содержащие цифры не одинаковые: %d, %d, %d.", digit1, digit2, digit3);
        }
    } else {
        printf("Число не трехзначное.");
    }
}