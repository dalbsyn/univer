#include <iostream>
using namespace std;

float count(float a, float b, float c){
    return (a * c) +(b * c);
}

int main(){
    setlocale(LC_ALL, "");
    float tetrad, oblozhka, kolichestvo, result;
    wcout << L"Вычисление стоимости покупки.\nВведите исходные данные:" << endl;
    wcout << L"Цена тетради -> ";
    wcin >> tetrad;
    wcout << L"Цена обложки -> ";
    wcin >> oblozhka;
    wcout << L"Количество комплектов -> ";
    wcin >> kolichestvo;
    result = count(tetrad, oblozhka, kolichestvo);
    wcout << L"Стоимость покупки -> " << result << endl;
}