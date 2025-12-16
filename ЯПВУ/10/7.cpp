#include<iostream>
using namespace std;

void fill_matric(int matrix[][7], int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (i == j){
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }
}

void output(const int matrix[][7], int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            wcout << matrix[i][j] << L"\t"; 
        }
        wcout << endl;
    }
}

int main(){
    setlocale(LC_ALL, "");

    int A[7][7];
    
    fill_matric(A, 7);

    wcout << L"\nПолученная единичная матрица:" << endl;
    output(A, 7);
}