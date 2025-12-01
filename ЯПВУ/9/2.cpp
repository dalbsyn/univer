#include<iostream>
using namespace std;

wchar_t sravnenie(wchar_t first, wchar_t second){
    wchar_t result;
    if (first < second){
        result = second;
    } else if (first > second){
        result = first;
    }
    return result;
}

int main(){
    setlocale(LC_ALL, "");

    wchar_t first, second;

    wcout << L"Введите первый символ: ";
    wcin >> first;
  
    wcout << L"Введите второй символ: ";
    wcin >> second;

    wchar_t result = sravnenie(first, second);

    wcout << L"Больший символ из " << first << L" и " << second << L": " << result;

}