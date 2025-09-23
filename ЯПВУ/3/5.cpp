#include <iostream>
using namespace std;

float count(float a, float b){
    return a* b;
}

int main(){
    setlocale(LC_ALL, "");
    float karta, tochka, result;
    wcout << L"Вычисление расстояния между населенными пунктами.\nВведите исходные данные:" << endl;
    wcout << L"Масштаб карты (количество километров в одном сантиметре) -> ";
    wcin >> karta;
    wcout << L"Расстояние между точками, изображающими населенные пункты (см) -> ";
    wcin >> tochka;
    result = count(karta, tochka);
    wcout << L"Расстояние между населенными пунктами " << result << L"км." << endl;
}