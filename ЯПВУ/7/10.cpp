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
    int n = 15;

    vector<int> numbers = int_array_gen(n, -10, 10);
    vector<int> absolute;

    printf("Полученный массив чисел: ");

    for (int i = 0; i < n; i++){
        cout << numbers[i] << " ";
    }

    cout << endl;

    printf("Исходный массив абсолютных значений: ");

    for (int i = 0; i < n; i++){
        int value = abs(numbers[i]);
        absolute.push_back(value);
        cout << value << " ";
        
    }

    sort(absolute.begin(), absolute.end());

    cout << endl;

    printf("Отсортированный массив абсолютных значений по возрастанию:");

    for (int i = 0; i < absolute.size(); i++){
        cout << absolute[i] << " ";
    }
}