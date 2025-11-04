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
    int amount = 0;

    printf("Введите элементы массива (10 целых чисел) в одной строке и нажмите <Enter> -> ");

    // считывание всей строки и сохранение в переменную
    getline(cin, numbers);

    // извлечение чисел из строк, а затем их внесение в статический массив.
    stringstream ss(numbers);
    int value;

    while (actual_count < max && (ss >> value)) {
        numbers_array[actual_count] = value;
        actual_count++;
    }

    int max_val = numbers_array[0];
    int min_val = numbers_array[0];

    // получение суммы, количества ненулевых значений и их суммы
    for (int i = 0; i <= max-1; ++i) {
        sum += numbers_array[i];
        amount++;
        if (numbers_array[i] > max_val){
            max_val = numbers_array[i];
        }
        if (numbers_array[i] < min_val){
            min_val = numbers_array[i];
        }
    }

    // приведение типа int к double, чтобы не терять дробную часть во время 
    // вычисления, так как иначе в результате теряется дробная часть.
    double sred_arith = static_cast<double>(sum - (max_val + min_val)) / (amount - 2);
    
    printf("Минимальный элемент: %i\nМаксимальный элемент: %i\n", min_val, max_val);
    printf("Среднее арифм. без учета min и max значений: %.2f", sred_arith);

}