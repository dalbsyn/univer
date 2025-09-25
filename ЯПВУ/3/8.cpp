#include <iostream>
#include <cmath>
using namespace std;

double side(double a, double h){
    return 5 * a * h;
}

double base_calc(double a){
    double under_sqrt, square, result;
    under_sqrt = 5 * (5 + 2 * sqrt(5));
    wcout << under_sqrt << endl;
    wcout << sqrt(under_sqrt) << endl;
    wcout << pow(a ,2) << endl;
    result = ((1 / 2) * sqrt(under_sqrt) * pow(a, 2));
    wcout << result;
    return result;
}
int main(){
    setlocale(LC_ALL, "");
    double a, h, surface, base;
    wcout << L"Введите значение для a: ";
    wcin >> a;
    wcout << L"Введите значение для h: ";
    wcin >> h;

    surface = side(a, h);
    base = base_calc(a);

    wcout << L"Площадь боковой поверхности: " << surface << endl;
    wcout << L"Площадь основания: " << base << endl;

}