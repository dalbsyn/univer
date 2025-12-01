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
    int n = 29;
    int count = 0;

    vector<int> numbers = int_array_gen(n, -10, 10);
    vector<int> nechet;

    printf("Полученный массив чисел: ");

    for (int i = 0; i < n; i++){
        cout << numbers[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < n - 1; i++){
        if (numbers[i] > 0 && numbers[i + 1] > 0){
            count++;
        }
    }

    printf("Количество пар, где идут два подряд положительных значения: %i", count);
}