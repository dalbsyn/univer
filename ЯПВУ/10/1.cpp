#include<iostream>
using namespace std;

double sred(int a[], int* max_ptr, int* min_ptr){
    int max = a[0];
    int min = a[0];
    int result = 0;

    for (int i = 0; i < 8; i++){
        if (a[i] > max){
            max = a[i];
        }
        if (a[i] < min){
            min = a[i];
        }
        result += a[i];
    }

    *max_ptr = max;
    *min_ptr = min;

    result = (result - (max + min)) / 6.0;

    return result;
}

int main(){
    setlocale(LC_ALL, "");
    srand(time(0));

    int a[8];
    int max;
    int min;

    wcout << L"Полученный массив: ";

    for (int i = 0; i < 8; i++){
        a[i] = 1 + rand() % 10;
        wcout << a[i] << " ";
    }

    double result = sred(a, &max, &min);

    wcout << endl;
    
    wcout << L"Средняя оценка без учета наибольшей и наименьшей оценки: " << result << " (" << max << " " << min << ")" << endl;
}