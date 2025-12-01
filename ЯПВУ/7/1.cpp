#include<iostream>
#include<random>
#include<ctime>
using namespace std;

int main(){
    srand(time(0));

    const int max = 9;
    int sred = 0;
    int osadki[max];

    printf("Осадки в мм для каждого года: ");

    for (int i = 0 ; i <= max; i++){
        // генерация значений осадков
        osadki[i] = 1+ rand() % 20;

        cout << osadki[i] << " ";

        sred += osadki[i];
    }

    cout << endl;

    sred = sred / max;

    printf("Среднее количество осадков %i\n", sred);

    printf("Отклонение осадков от срденего (год, осадок, отклонение): ");

    for (int i = 0; i <= max; i++){
        // расчет отклонения
        int result = sred - osadki[i];
        printf("\n[%i] %i = %i", i, osadki[i], result);
    }
}