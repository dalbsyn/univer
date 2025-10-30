#include<iostream>
using namespace std;

int main(){
    int i, n;
    float prev = 0;

    wcout << L"";
    printf("Введите количество вычисляемых чисел ряда: ");

    wcin >> n;

    for (i = 1; i <= n; i++){
        prev = prev + 1.0/i;
        printf("1/%d - %f\n", i, prev);
    }
}