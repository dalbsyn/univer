#include<iostream>
using namespace std;

int main(){
    int numbers [5];
    int non_zero = 0;

    printf("Ввод массива целых чисел.\nПосле ввода каждого числа нажмите <Enter>\n");

    for (int i = 1; i <= 5; i++){
        printf("a[%i] -> ", i);
        cin >> numbers [i];
        if (numbers [i] != 0){
            non_zero++;
        }
    }

    printf("В массиве %i ненулевых элемента", non_zero);
}