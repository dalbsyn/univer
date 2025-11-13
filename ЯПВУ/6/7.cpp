#include<iostream>
#include<sstream> //для stringstream
#include<string>
using namespace std;

int main(){
    const int max = 10;
    int numbers_array [max];
    int amount_array [max];
    int prev[max];
    string numbers;
    int actual_count = 0;
    int value = 0;

    // По умочанию целочисленный массив инициализируется странными значениями,
    // хотя думал, что изначально все значения является нулями. 
    // Поэтому этим циклом все значения устанавливаю в 0, чтобы потом считать
    // количество повторений числа.
    for (int i = 0; i <= max; i++){
        amount_array[i] = 0;
        prev[i] = 0;
    }

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

    // Считает количество повторений какого-то числа и сохраняет в массив. Так
    // как массивы имеют одинаковую длину и порядок не меняется, то так будет
    // проще связать число и количество повторений. 
    for (int i = 0; i <= max; i++){
        for (int j = 0; j <= max; j++){
            if (numbers_array[i] == numbers_array[j]){
                ++amount_array[i];
            }
        }

    }

    // Вывод числа и его количества повторений.
    // Не застрахован от случаев, когда элемент массива чисел не заполнен
    // числом (т.е. будет какое-то странное огромное или маленькое число) и
    // выводит количество повторений для каждого элемента массив, т.е. в
    // выводе элементы будут повторяться. 
    for (int i = 0; i <= max; i++){
        printf("Число %i повторяется %i раза\n", numbers_array[i], amount_array[i]);
    }
}
