#include<iostream>
#include<cmath>   // pow()
using namespace std;

double geomsred(const int arr[], int size){
    if (size <= 0) {
        return 0.0;
    }

    double product = 1.0;

    for (int i = 0; i < size; i++){
        // множество значений элементов, с преобразованием в double
        product *= (double)arr[i]; 
    }
    
    return pow(product, 1.0 / size);
}

void output(const int a[], int size){
    wcout << L"[ ";
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

    int scores[12];

    wcout << L"Оценки 12 студентов: ";
    for (int i = 0; i < 12; i++){
        scores[i] = 1 + rand() % 100; 
    }
    
    output(scores, 12);

    double avg = geomsred(scores, 12);
    
    wcout << L"Среднее геометрическое для оценки группы: " << avg << endl;
}