#include<iostream>
#include<cmath>   // fabs()
using namespace std;

double find_minimal(const double arr[], int size){
    if (size <= 0) {
        return 0.0;
    }

    double minimal_value = arr[0]; 
    
    for (int i = 1; i < size; i++){
        if (fabs(arr[i]) < fabs(minimal_value)){
            // запоминаем сам элемент, а не его модуль
            minimal_value = arr[i]; 
        }
    }
    
    return minimal_value;
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
    wcout << L" ]" << endl;
}

int main(){
    setlocale(LC_ALL, "");
    srand(time(0));

    double a[10];

    fill_array(a, 10);

    wcout << L"Исходный массив действительных чисел: ";
    
    output(a, 10);

    double result = find_minimal(a, 10);
    
    wcout << L"Наименьшее по модулю значение: " << result << endl;

    wcout << L"Его модуль: " << fabs(result) << endl;
}