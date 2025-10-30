#include<iostream>
using namespace std;

int main(){
    int i;
    printf("Таблица квадратов\n");
    printf("Число\tКвадрат\n");

    for (i = 1; i <= 10; i++){
        printf("%d\t%d\n", i, i * i);
    }
}