#include<iostream>
#include<vector> // для vector
#include<ctime> // чтобы генератор случайных чисел генерировал случайные числа 
#include<random> // для mt19937
#include<cmath> // для abs
#include<algorithm> // для sort
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
    int n = 21;
    int p = 0;
    int biggerp = 0;
    int lowerp = 0;

    printf("Введите число P: ");
    cin >> p;

    vector<int> numbers = int_array_gen(n, -10, 10);
    vector<int> sorted;

    printf("Полученный массив чисел: ");

    for (int i = 0; i < n; i++){
        sorted.push_back(numbers[i]);
        cout << numbers[i] << " ";
    }
    
    sort(sorted.begin(), sorted.end());

    cout << endl;

    printf("Отсортированный массив чисел по возрастанию:");

    for (int i = 0; i < sorted.size(); i++){
        cout << sorted[i] << " ";
    }

    for (int i = 0; i < sorted.size(); i++){
        if (sorted[i] > p){
            ++biggerp;
        } else if (sorted[i] < p){
            ++lowerp;
        }
    }

    cout << endl;

    if(biggerp > lowerp){
        printf("В массиве больше значений, которые больше, чем P: %i (меньше P: %i)", biggerp, lowerp);
    } else if (lowerp > biggerp){
        printf("В массиве больше значений, которые меньше, чем P: %i (больше P: %i)", lowerp, biggerp);
    }
}