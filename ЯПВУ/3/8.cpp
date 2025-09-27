#include <iostream>
#include <cmath>
using namespace std;

double side(double a, double h){
	double perimetr = a * 5;
	return perimetr * h;
}

double base_calc(double a){
	double cot;
	// Котангенса не существует в std::math🤯
	cot = 1/tan(M_PI/5);

	// В C++ вычисления только с int-числами приводят к результату в виде int
	// и только int. Если хоть одно из чисел будет double (float), то и
	// результат будет float.
	// Использование только int-чисел приводит к огромной неточности в
	// вычислениях с не менее огромными числами из-за отсутствия чисел после
	// точки, которые создают эту разницу.
	return ((5.0/4.0) * (pow(a, 2)) * cot);
}

int main(){
    setlocale(LC_ALL, "");
    double a, h, surface, base, result;
	a = 5;
	h = 4;
    wcout << L"Введите значение для a: ";
    wcin >> a;
    wcout << L"Введите значение для h: ";
    wcin >> h;

    surface = side(a, h);
    base = base_calc(a);
	result = 2 * base + surface;

    wcout << L"Площадь боковой поверхности: " << surface << L" кв.ед." << endl;
    wcout << L"Площадь основания: " << base << L" кв.ед." << endl;
	wcout << L"Результат: " << result << L" кв.ед." << endl;

}
