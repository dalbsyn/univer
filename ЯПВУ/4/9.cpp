#include<iostream>
using namespace std;

float procent(float number){
    return number/100.00;
}

int main(){
    float kolich, cena; // количество, цена
    printf("Введите количество товара: ");
    wcin >> kolich;
    printf("Введите цену за товар: ");
    wcin >> cena;

    float summary = kolich * cena;

    if (kolich > 0 && kolich <= 100){
        printf("Скидка 0%, сумма: %.3f.", summary);
    } else if (kolich >= 100 && kolich <= 200){
        float result = summary - (summary * procent(3));
        printf("Скидка 3%, сумма со скидкой: %.3f.", result);
    } else if (kolich >= 200 && kolich <= 300){
        float result = summary - (summary * procent(5));
        printf("Скидка 5%, сумма со скидкой: %.3f.", result);
    } else if (kolich >= 300){
        float result = summary - (summary * procent(7));
        printf("Скидка 7%, сумма со скидкой: %.3f.", result);
    } else {
        printf("Введено неверное значение количества.");
    }
}