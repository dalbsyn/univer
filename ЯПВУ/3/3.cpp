#include <iostream>
using namespace std;

float count(float a, float b, float c){
    return a * b * c;
}

int main(){
    float a, b, c, result;
    setlocale(LC_ALL, "");
    wcout << L"Вычисление объема параллелепипеда.\nВведите исходные данные:" << std::endl;
    wcout << L"Длина (см) -> ";
    wcin >> a;
    wcout << L"Ширина (см) -> ";
    wcin >> b;
    wcout << L"Высота (см) -> ";
    wcin >> c;
    result = count(a, b, c);
    wcout << L"Объем: " << result << L" куб.см." << std::endl;
}