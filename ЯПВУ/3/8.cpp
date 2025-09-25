#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double a, b, h, surface;
    wcout << "Введите значение для a: ";
    wcin >> a;
    wcout << "Введите значение для b: ";
    wcin >> b;
    wcout << "Введите значение для h: ";
    wcin >> h;
    surface =  (5 * a *b + 5 * b * h);
    wcout << "Площадь: " << surface << endl;
}