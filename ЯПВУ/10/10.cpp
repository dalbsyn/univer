#include<iostream>
using namespace std;

int find_otric(const int arr[], int size){
    if (size <= 0) {
        return -1;
    }

    for (int i = 0; i < size; i++){
        if (arr[i] < 0){
            return i;
        }
    }
    
    return -1;
}

void fill(int a[], int size, bool includeNegative){
    for (int i = 0; i < size; i++){
        a[i] = rand() % 11 - 5; 
        
        if (!includeNegative && a[i] < 0) {
            a[i] = -a[i];
        }
    }
}

void output(const int a[], int size){
    wcout << L"[ ";
    for (int i = 0; i < size; i++){
        wcout << a[i];
        wcout << L" ";
    }
    wcout << L"]" << endl;
}

int main(){
    setlocale(LC_ALL, "");
    srand(time(0));

    int data1[10];
    int data2[10];

    fill(data1, 10, true);

    wcout << L"Массив: ";
    output(data1, 10);

    int index1 = find_otric(data1, 10);

    wcout << L"Индекс первого отрицательного элемента: " << index1;
    if (index1 != -1) {
        wcout << L" (Значение: " << data1[index1] << L")";
    }
}