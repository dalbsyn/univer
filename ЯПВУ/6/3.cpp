#include<iostream>
#include<sstream> //для stringstream
#include<string>
using namespace std;

int main(){
    const int max = 10;
    int numbers_array [max];
    string numbers;
    int actual_count = 0;

    // результаты вычисления
    int sum = 0;
    int non_zero = 0;
    float sum_non_zero = 0;

    printf("Введите элементы массива (10 целых чисел) в одной строке и нажмите <Enter>.\n");

    // считывание всей строки и сохранение в переменную
    getline(cin, numbers);

    // извлечение чисел из строк, а затем их внесение в статический массив.
    stringstream ss(numbers);
    int value;

    while (actual_count < max && (ss >> value)) {
        numbers_array[actual_count] = value;
        actual_count++;
    }

    // получение суммы, количества ненулевых значений и их суммы
    for (int i = 0; i <= max-1; ++i) {
        sum += numbers_array[i];
        if (numbers_array[i] != 0){
            non_zero++;
            sum_non_zero += numbers_array[i];
        }
    }

    // среднее арифметическое
    float sred_arith = sum_non_zero / non_zero;
    
    printf("Сумма элементов массива: %i\nКоличество ненулевых элементов: %i\nСреднее арифметическое ненулевых элементов %.2f", sum, non_zero, sred_arith);
}