#include<iostream>
#include<vector> // для vector
#include<ctime> // чтобы генератор случайных чисел генерировал случайные числа 
#include<random> // для mt19937
#include<limits> // для инициализации min_value
using namespace std;

// Функция генерации целочисленной матрицы N x M
vector<vector<int>> int_matrix_gen(int n, int m, int start, int end){
    // инициализация генератора случайных значений Мерсенна-Твистера и
    // задание диапазона генерируемых значений
    mt19937 mt(time(0));
    uniform_int_distribution<> distrib(start, end);
    // Инициализация матрицы N x M
    vector<vector<int>> matrix(n, vector<int>(m));
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            matrix[i][j] = distrib(mt);
        }
    }

    return matrix;
}

int main(){
    int n_rows = 0;
    int m_cols = 0;
    // Инициализация min_value максимально возможным значением
    int min_value = numeric_limits<int>::max(); 
    
    printf("Введите количество строк N: ");
    cin >> n_rows;
    printf("Введите количество столбцов M: ");
    cin >> m_cols;

    // Генерация матрицы (целые числа, например, от -10 до 10)
    vector<vector<int>> matrix = int_matrix_gen(n_rows, m_cols, -10, 10);

    // Шаг 1: Вывод матрицы и поиск минимального элемента
    printf("\nПолученная матрица (%i x %i):\n", n_rows, m_cols);

    for (int i = 0; i < n_rows; i++){
        for (int j = 0; j < m_cols; j++){
            cout << matrix[i][j] << "\t";

            if (matrix[i][j] < min_value){
                min_value = matrix[i][j];
            }
        }
        cout << endl;
    }
    
    printf("\nМинимальный элемент в матрице: %i\n", min_value);

    // Шаг 2: Расчет и вывод отклонений (min_value - A[i][j])
    printf("\nМатрица отклонений от минимального элемента:\n");

    for (int i = 0; i < n_rows; i++){
        for (int j = 0; j < m_cols; j++){
            // Отклонение = min_value - A[i][j]
            // Отклонение будет отрицательным, если A[i][j] > min_value
            int deviation = min_value - matrix[i][j];
            cout << deviation << "\t";
        }
        cout << endl;
    }
}