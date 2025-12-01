#include<iostream>
using namespace std;

void stroka(wchar_t bukva = L'Ы', int dlina = 200){
    // char = '', хранит только сам символ
    // char * = "", хранит сам символ и конец строки (\0)
    // уточнение важное, так как из-за путаницы типов невозможна нормальная работа
    for(int i = 0; i < dlina; i++){
        wcout << bukva;
    }
}

int main(){
    setlocale(LC_ALL, "");

    wcout << L"Результат: ";

    // вызов функции с параметрами по умолчанию
    stroka();
}