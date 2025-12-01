#include<iostream>
using namespace std;

double cilinder(int rad, int h){
    const double pi = 3.14;
    
    double result = pi * rad * rad * h;
    
    return result;
}

int main(){
    int rad, h;

    printf("Введите радиус: ");
    cin >> rad;

    printf("Введите высоты: ");
    cin >> h;

    double result = cilinder(rad, h);

    printf("Результат вычисления: %.2f", result);
}