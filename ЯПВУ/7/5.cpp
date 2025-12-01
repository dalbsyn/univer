#include<iostream>
#include<random>
#include<ctime>
using namespace std;

int main(){
    srand(time(0));

    const int maxl = 23;
    int sred = 0;
    int max = 0;
    int min = 0;
    int temp[maxl];

    printf("Температура воздуха в течение дня: ");

    for (int i = 0 ; i <= maxl; i++){
        // генерация значений осадков
        temp[i] = 1+ rand() % 20;

        cout << temp[i] << " ";

        sred += temp[i];
    }

    cout << endl;

    sred = sred / maxl;

    printf("Средняя температура воздуха: %i\n", sred);
    
    int prev = temp[0];
    for (int i = 0; i <= maxl; i++){
        if (temp[i] < prev){
            prev = temp[i];
            min = prev;
        }
    }

    printf("Минимальная температура воздуха: %i\n", min);

    prev = temp[0];
    for (int i = 0; i <= maxl; i++){
        if (temp[i] > prev){
            prev = temp[i];
            max = prev;
        }
    }

    printf("Минимальная температура воздуха: %i\n", max);
}