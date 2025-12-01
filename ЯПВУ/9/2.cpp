#include<iostream>
using namespace std;

int sravnenie(int first, int second){
    int result = 0;
    if (first < second){
        result = second;
    } else if (first > second){
        result = first;
    }
    return result;
}

int main(){
    int first, second;

    printf("Введите первое число: ");
    cin >> first;
  
    printf("Введите второе число: ");
    cin >> second;

    int result = sravnenie(first, second);

    printf("Большее число из %i и %i: %i", first, second, result);
}