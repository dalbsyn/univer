#include<iostream>
using namespace std;

int soprotivlenie(int r1, int r2, int type){
    // type = 1 - последовательное
    // type = 2 - параллельное
    int result = 0;

    if (type == 1){
        result = r1 + r2;
    } else if (type == 2){
        result = ((r1 * r2) / (r1 + r2)); 
    } else {
        result = -1;
    }

    return result;
}

int main(){
    setlocale(LC_ALL, "");

    int r1, r2, type;

    wcout << L"Введите сопротивление первого проводника: ";
    wcin >> r1;

    wcout << L"Введите сопротивление второго проводника: ";
    wcin >> r2;

    wcout << L"Выберите тип соединения (1 - последовательное, 2 - параллельное): ";
    wcin >> type;

    wcout << L"Результат: " << soprotivlenie(r1, r2, type);
}