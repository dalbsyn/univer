#include<iostream>
#include<vector> // для vector
#include<ctime> // чтобы генератор случайных чисел генерировал случайные числа 
#include<random> // для mt19937
using namespace std;

vector<vector<int>> int_matrix_gen(int n, int start, int end){
    // инициализация генератора случайных значений Мерсенна-Твистера и
    // задание диапазона генерируемых значений
    mt19937 mt(time(0));
    uniform_int_distribution<> distrib(start, end);
    // Инициализация квадратной матрицы N x N
    vector<vector<int>> matrix(n, vector<int>(n));
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            matrix[i][j] = distrib(mt);
        }
    }

    return matrix;
}

int main(){
    int matrix_size = 0;
    long long sum_elements = 0; // Для предотвращения переполнения
    
    printf("Введите размерность N квадратной матрицы: ");
    cin >> matrix_size;

    vector<vector<int>> matrix = int_matrix_gen(matrix_size, 1, 10);

    printf("\nПолученная матрица (размер %i x %i):\n", matrix_size, matrix_size);

    for (int i = 0; i < matrix_size; i++){
        for (int j = 0; j < matrix_size; j++){
            cout << matrix[i][j] << "\t";
        }
        cout << endl; // Переход на новую строку после каждой строки матрицы
    }
    
    // Вычисление суммы элементов ниже главной диагонали (i > j)
    for (int i = 0; i < matrix_size; i++){
        for (int j = 0; j < matrix_size; j++){
            if (i > j){
                sum_elements += matrix[i][j];
            }
        }
    }

    printf("\nСумма элементов, расположенных ниже главной диагонали: %lld\n", sum_elements);
}