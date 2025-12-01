#include<iostream>
using namespace std;

void razmery(int a, int b, int c, int* result_pl, int* result_ob){
    // площадь
    *result_pl = 2 * (a * b + b * c + a * c);

    // объем
    *result_ob = a * b * c;
}

int main(){
    setlocale(LC_ALL, "");

    int a, b, c, result_pl, result_ob;

    wcout << L"Введите A: ";
    wcin >> a; 

    wcout << L"Введите B: ";
    wcin >> b; 

    wcout << L"Введите C: ";
    wcin >> c; 

    razmery(a, b, c, &result_pl, &result_ob);

    wcout << L"Объем поверхности параллелепипеда: " << result_ob << endl;
    wcout << L"Площадь поверхности параллелепипеда: " << result_pl << endl;

}
