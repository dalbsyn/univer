#include<iostream>
#include<cmath>
using namespace std;

int tenge(float money){
    return floor(money);
}

int tiyn(float money){
    double f;
    return modf(money, &f) * 100;
}

int main(){
    setlocale(LC_ALL, "");
    float money;
    wcout << L"Преобразование числа в денежный формат." << endl;
    wcout << L"Введите дробное число -> ";
    wcin >> money;
    wcout << money << L" тенге. " << L"Это " << tenge(money) << L" тенге " << tiyn(money) << L" тиын." << endl;
}