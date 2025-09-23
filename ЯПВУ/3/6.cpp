#include <iostream>
#include <list>
using namespace std;

int main(){
    setlocale(LC_ALL, "");
    float distance, time;
    wcout << L"Вычисление скорости бега." << endl;
    wcout << L"Введите длину дистанции (метров) -> ";
    wcin >> distance;
    wcout << L"Введите время (минут.секунд)-> ";
    wcin >> time;
    wcout << L"Дистанция: " << distance;
    wcout << L"Время: ";
    wcout << "Вы бежали со скоростью";
}