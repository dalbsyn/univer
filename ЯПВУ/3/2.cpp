#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "");
    float kilometr;
    wcout << L"ВВЕДИТЕ ЗНАЧЕНИЕ: ";
    wcin >> kilometr;
    float result {(kilometr * 1000) / 1066.8};
    wcout << L"Перевод километров в версты: " << result;
}