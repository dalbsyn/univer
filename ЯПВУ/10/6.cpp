#include<iostream>
#include<cmath>   // fabs()
using namespace std;

int find_max(const double arr[], int size){
    if (size <= 0) {
        return -1; // если массив пуст
    }

    int max_index = 0;
    double max_value = fabs(arr[0]);

    for (int i = 1; i < size; i++){
        double current = fabs(arr[i]);
        
        if (current > max_value){
            max_value = current; 
            max_index = i;
        }
    }
    
    return max_index;
}

void fill_array(double a[], int size){
    for (int i = 0; i < size; i++){
        a[i] = (rand() % 200) / 10.0 - 10.0; 
    }
}

void output(const double a[], int size){
    wcout << L"[ ";
    wcout << fixed;
    for (int i = 0; i < size; i++){
        wcout << a[i];
        if (i < size - 1) {
            wcout << L", ";
        }
    }
    wcout << L" ]";
}

int main(){
    setlocale(LC_ALL, "");
    srand(time(0));

    double data[9];

    fill_array(data, 9);

    wcout << L"Исходный массив действительных чисел: ";
    output(data, 9);

    int maxindex = find_max(data, 9);
    
    wcout << L"\nЭлемент с максимальным модулем: " << data[maxindex] << L" (Индекс: " << maxindex << L", Модуль: " << fabs(data[maxindex]) << L")";
              
    for (int i = 0; i < 9; i++){
        if (i != maxindex) {
            data[i] *= 2.0;
        }
    }
    
    wcout << endl;

    wcout << L"Преобразованный массив: ";
    output(data, 9);
}