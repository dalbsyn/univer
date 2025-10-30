#include<iostream>
using namespace std;

int main(){
    int i, n;

    int prev = 0;
    int iter = -1;

    printf("Введите число суммируемых первых чисел: ");
    wcin >> n;

    for (i = 1; i <= n; i++){
        prev =  iter-- + prev;
        wcout << prev << "\n";
    }
}