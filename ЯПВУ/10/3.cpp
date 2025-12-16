#include<iostream>
using namespace std;

void fill(int a[], int size){
    for (int i = 0; i < size; i++){
        a[i] = 1 + rand() % 10; 
    }
}

void print(const int a[], int size){
    wcout << L"[ ";
    for (int i = 0; i < size; i++){
        wcout << a[i];
        if (i < size - 1) {
            wcout << L", ";
        }
    }
    wcout << L" ]" << endl;
}

void swap(int a[], int size){
    for (int i = 0; i < size - 1; i += 2){
        int temp = a[i];
        a[i] = a[i+1];
        a[i+1] = temp;
    }
}

int main(){
    setlocale(LC_ALL, "");
    srand(time(0));

    int a[8];

    wcout << L"Исходный массив: ";
    fill(a, 8);
    
    print(a, 8);

    swap(a, 8);

    wcout << L"Массив после перестановки: ";
    print(a, 8);    
}