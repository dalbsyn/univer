#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int i;
    int n = 10;
    int prev = 0;

    printf("Таблица степеней двойки\n");

    for (i = 0; i <= n; i++){
        if (i == 0){
            printf("0\t1\n");
        }
        else if (i == 1){
            printf("1\t2\n");
        }
        else{
            printf("%i\t%i\n", i, i * i);
        }
    }
}