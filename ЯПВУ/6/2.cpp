#include<iostream>
#include<sstream> //для stringstream
#include<string>
using namespace std;

int main(){
    const int max = 5;
    int numbers_array [max];
    string numbers;
    int actual_count = 0;
    int min_num = 0;

    printf("Поиск минимального элемента массива.\nВведите в одной строке элементы массива (5 целых чисел) и нажмите <Enter>.\n");

    // считывание всей строки и сохранение в переменную
    getline(cin, numbers);

    // извлечение чисел из строк, а затем их внесение в статический массив.
    stringstream ss(numbers);
    int value;

    while (actual_count < max && (ss >> value)) {
        numbers_array[actual_count] = value;
        actual_count++;
    }

    // чтобы в первом проходе было с чем сравнивать.
    min_num = numbers_array[0];

    // само получение минимального элемента массива
    for (int i = 0; i <= max-1; ++i) {
        if (numbers_array[i] < min_num){
            min_num = numbers_array[i];
        }
    }

    printf("Минимальный элемент массива: %i", min_num);
}