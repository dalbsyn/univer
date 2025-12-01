#include<iostream>
using namespace std;

char* sravnenie(int first, int second){
    char* result;

    if (first < second){
        result = "<";
    } else if (first > second){
        result = ">";
    } else if (first == second){
        result = "=";
    }
    return result;
}

int main(){
    int first, second;

	printf("Введите первое число: ");
	cin >> first;

	printf("Введите второе число: ");
	cin >> second;

	char* result = sravnenie(first, second);

	printf("Результат сравнения чисел %i и %i: %s", first, second, result);
}
