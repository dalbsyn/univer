#include<iostream>
#include<vector>
#include<ctime>
#include<random>
using namespace std;

vector<int> int_array_gen(int length, int start, int end){
    // инициализация генератора случайных значений Мерсенна-Твистера и
    // задание диапазона генерируемых значений
    mt19937 mt(time(0));
    uniform_int_distribution<> distrib(start, end);
    vector<int> array;
    
    for (int i = 0; i < length; i++){
        int random_value = distrib(mt);
        array.push_back(random_value);
    }

    return array;
}

int main(){
    srand(time(0));
    bool otricat = false;
    int n = 10;

    vector<int> numbers = int_array_gen(n, -4, 4);

    printf("Полученный массив чисел: ");

    for (int i = 0; i < n; i++){
        cout << numbers[i] << " ";
    }

    for (int i = 0; i < n; i++){
        if (numbers[i] < 0){
            if (numbers[i] % 2 != 0){
                otricat = true;
                printf("\nНечетное отрицательное число %i на позиции %i", numbers[i], i);
            }
        }
    }
    if (otricat == false){
        printf("\nНечетных отрицательных чисел нет.");
    }
}