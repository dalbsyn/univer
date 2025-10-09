#include<iostream>
using namespace std;

int main(){
    int number;
    printf("Введите число от 0 до 100000: ");
    wcin >> number;
    if (number >= 0 && number <= 100000){
        int digit1 = number / 100000;
        int digit2 = (number / 10000) % 10;
        int digit3 = (number / 1000) % 10;
        int digit4 = (number / 100) % 10;
        int digit5 = (number / 10) % 10;
        int digit6 = number % 10;
        printf("Результат: %d %d %d %d %d %d", digit1, digit2, digit3, digit4, digit5, digit6);
    } else {
        printf("Число вышло за пределы допустимого диапазона.");
    }
}