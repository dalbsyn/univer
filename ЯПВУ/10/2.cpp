#include<iostream>
using namespace std;

void ball(int ocenki[]){
    int result = 0;

    for (int i = 0; i < 8; i++){
        if (ocenki[i] >= 90 and ocenki[i] <= 100){
            result = 5;
        } else if (ocenki[i] >= 70 and ocenki[i] <= 89){
            result = 4;
        } else if (ocenki[i] >= 50 and ocenki[i] <= 69){
            result = 3;
        } else {
            result = 2;
        }

        wcout << endl;

        wcout << L"Результат для студента " << i+1 << ": " << result;
    }
}

int main(){
    setlocale(LC_ALL, "");
    srand(time(0));

    int a[8];

    wcout << L"Полученный массив: ";

    for (int i = 0; i < 8; i++){
        a[i] = 1 + rand() % 100;
        wcout << a[i] << " ";
    }

    ball(a);
}