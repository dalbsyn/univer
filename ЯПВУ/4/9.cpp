#include<iostream>
using namespace std;

float procent(int number){
    int result = number/100;
    wcout << result;
    return result;
}
int main(){
    int kolich, cena; // количество, цена
    printf("Введите количество товара: ");
    wcin >> kolich;
    printf("Введите цену за товар: ");
    wcin >> cena;
    if (kolich > 0 && kolich <= 100){
        printf("Скидка 0%, сумма: %d.", (kolich * cena));
    } else if (kolich >= 100 && kolich <= 200){
        printf("%d", procent(3));
        printf("Скидка 3%, сумма со скидкой: %d.", ((kolich * cena * procent(3))));
    } else if (kolich >= 200 && kolich <= 300){
        printf("Скидка 5%, сумма со скидкой: %d.", ((kolich * cena * procent(5))));
    } else if (kolich >= 300){
        printf("Скидка 7%, сумма со скидкой: %d.", ((kolich * cena * procent(7))));
    } else {
        printf("Введено неверное значение количества.");
    }
}