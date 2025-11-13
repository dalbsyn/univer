#include<iostream>
#include<string>
using namespace std;

int main(){
    const int max = 4;
    int ocenki[max];
    int results[max];
    float sum = 0;

    printf("Обработка результатов экзамена.\n");

    printf("Пятерок -> ");
    cin >> ocenki[0];

    printf("Четверок -> ");
    cin >> ocenki[1];

    printf("Троек -> ");
    cin >> ocenki[2];

    printf("Двоек -> ");
    cin >> ocenki[3];

    for(int i = 0; i < max; i++){
        sum += ocenki[i];
    }

    for(int i = 0; i < max; i++){
        results[i] = (ocenki[i] / sum) * 100.0;
    }

    printf("\nРезультаты экзамена\n");
    printf("Пятерок - %i%\n", results[0]);
    printf("Четверок - %i%\n", results[1]);
    printf("Троек - %i%\n", results[2]);
    printf("Двоек - %i%\n", results[3]);
}
