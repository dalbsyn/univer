#include<iostream>
using namespace std;

int main(){
    int i, n;

    int prev = 0;

    printf("Введите число суммируемых первых чисел: ");
    wcin >> n;

    for (i = 1; i <= n; i++){
        prev = i + prev;
        wcout << prev << "\n";
    }
}