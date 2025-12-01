#include<iostream>
#include<random>
#include<ctime>
using namespace std;

int main(){
    srand(time(0));

    const int max = 8; // максимальное число значений в массиве (для результатов)
    int prev = 0; // минимальное значение
    int array[max - 1]; // результаты вычисления выражения
    int numbers[(max * 2) - 1]; // массив сгенерированных чисел
    int secound_i = 7; // костыль для второго элемента выражения
    
    printf("Полученные числа: ");

    for (int i = 0; i <= (max * 2) - 1; i++){
        // Генерация чисел от 1 до 100
        numbers[i] = 1 + rand() % 100;
        printf("%i ", numbers[i]);
    }
    
    cout << endl;

    for (int i = 0; i <= max; i++){
        // Вычисление и сохранение a(N) * a(N+1)
        array[i] = numbers[i] * numbers[secound_i];
        printf("[a%i * a%i] %i * %i = %i\n", i, secound_i, numbers[i], numbers[secound_i], numbers[i] * numbers[secound_i]);
        ++secound_i;
    }

    // Начало сравнения с первого значения
    prev = array[0];

    for (int i = 0; i <= max; i++){
        // Сравнение - если предыдущее значение больше текущего, то предыдущим
        // становится текущий. Так найдется минимальное значение.
        if(prev > array[i]){
            prev = array[i];
        }
    }

    printf("min = %i", prev);
}