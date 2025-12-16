#include<iostream>
using namespace std;

void invert_znaki(double matrix[][5], int rows, int column_index){
    if (column_index < 0 || column_index >= 5) {
        wcout << L"Некорректный индекс столбца." << endl;
        return;
    }

    for (int i = 0; i < rows; i++){
        matrix[i][column_index] = -matrix[i][column_index];
    }
}

void fill_matric(double matrix[][5], int rows){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < 5; j++){
            matrix[i][j] = (rand() % 200) / 10.0 - 10.0; 
        }
    }
}

void output(const double matrix[][5], int rows){    
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < 5; j++){
            wcout << matrix[i][j] << L"\t"; 
        }
        wcout << endl;
    }
}

int main(){
    setlocale(LC_ALL, "");
    srand(time(0));

    double A[4][5];
    int inverted = 0;

    wcout << L"Введите индекс столбца, который нужно инвертировать: ";
    wcin >> inverted;
    
    fill_matric(A, 4);

    wcout << L"Исходная матрица " << 4 << L"x" << 5 << endl;
    
    output(A, 4);
    
    invert_znaki(A, 4, inverted);
    
    wcout << L"Преобразованная матрица:" << endl;
    output(A, 4);
}