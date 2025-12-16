#include<iostream>
#include<algorithm>
using namespace std;

double extremes(const int matrix[][5], int rows, int cols){
    double totalSum = 0.0;

    for (int i = 0; i < rows; i++){
        if (i % 2 == 0){ 
            // максимальный элемент в нечетной строке
            int max_val = matrix[i][0];
            for (int j = 1; j < cols; j++){
                if (matrix[i][j] > max_val){
                    max_val = matrix[i][j];
                }
            }
            totalSum += max_val;
            wcout << L"Строка " << i + 1 << L" (нечетная): Max = " << max_val << endl;
        } 
        else { 
            // минимальный элемент в четной строке
            int min_val = matrix[i][0];
            for (int j = 1; j < cols; j++){
                if (matrix[i][j] < min_val){
                    min_val = matrix[i][j];
                }
            }
            totalSum += min_val;
            wcout << L"Строка " << i + 1 << L" (четная): Min = " << min_val << endl;
        }
    }
    
    return totalSum;
}

void fill_matric(int matrix[][5], int rows){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < 5
        ; j++){
            matrix[i][j] = rand() % 21 - 10; 
        }
    }
}

void output(const int matrix[][5], int rows){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < 5
        ; j++){
            wcout << matrix[i][j];
            if (matrix[i][j] >= 0) wcout << L" ";
            wcout << L"\t"; 
        }
        wcout << endl;
    }
}

int main(){
    setlocale(LC_ALL, "");
    srand(time(0));

    int A[4][5];
    
    fill_matric(A, 4);

    wcout << L"Исходная матрица: " << 4 << L"x" << 5 << endl;
    
    output(A, 4);

    wcout << L"Вычисление экстремальных сумм: " << endl;
    
    double finalSum = extremes(A, 4, 5);
    
    wcout << L"Общая сумма: " << finalSum << endl;
}