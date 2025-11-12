#include<iostream>
#include<sstream> //для stringstream
#include<string>
using namespace std;

int main(){
    const int max = 10;
    int numbers_array [max];
    string numbers;
    int actual_count = 0;
    int value = 0;
    int amount = 0;

    printf("Введите элементы массива (10 целых чисел) в одной строке и нажмите <Enter> -> ");

    // считывание всей строки и сохранение в переменную
    getline(cin, numbers);

    // извлечение чисел из строк, а затем их внесение в статический массив.
    stringstream ss(numbers);

    while (actual_count < max && (ss >> value)) {
        numbers_array[actual_count] = value;
        actual_count++;
    }

    cout << "Введенный массив: " << numbers << endl;

    printf("Введите искомое число -> ");

    cin >> value;

    for (int i = 0; i <= max; i++){
        for (int j = 0; j <= max; j++){
            if (i == j){
                amount++;
            }
        }
    }
    cout << amount;
}    int prev = 0;
