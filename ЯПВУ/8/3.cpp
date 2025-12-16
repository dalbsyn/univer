#include<iostream>
#include<vector> // для vector
#include<ctime> // чтобы генератор случайных чисел генерировал случайные числа 
#include<random> // для mt19937
#include<limits> // для инициализации min_value
using namespace std;

vector<vector<double>> double_matrix_gen(int n, int m, double start, double end){
    // инициализация генератора случайных значений Мерсенна-Твистера и
    // задание диапазона генерируемых значений
    mt19937 mt(time(0));
    // для вещественных чисел (double)
    uniform_real_distribution<> distrib(start, end); 
    vector<vector<double>> matrix(n, vector<double>(m));
    
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
    // Инициализация min_value максимально возможным значением, 
    // чтобы первый элемент гарантированно стал минимальным
    double min_value = numeric_limits<double>::max(); 
    int min_row = 0; // Строка минимального элемента
    int min_col = 0; // Столбец минимального элемента
    
    printf("Введите количество строк N: ");
    cin >> n_rows;
    printf("Введите количество столбцов M: ");
    cin >> m_cols;

    vector<vector<double>> matrix = double_matrix_gen(n_rows, m_cols, -20.0, 20.0);

    // Установка точности
    cout.setf(ios::fixed);
    cout.precision(2);

    printf("\nПолученная матрица (%i x %i):\n", n_rows, m_cols);

    // Вывод матрицы и одновременный поиск минимального элемента
    for (int i = 0; i < n_rows; i++){
        for (int j = 0; j < m_cols; j++){
            cout << matrix[i][j] << "\t";

            if (matrix[i][j] < min_value){
                min_value = matrix[i][j];
                min_row = i;
                min_col = j;
            }
        }
        cout << endl;
    }
    
    printf("\nМинимальный элемент в матрице: %.2f\n", min_value);
    printf("Местоположение минимального элемента (индексы с 0): Строка [%i], Столбец [%i]\n", min_row, min_col);
}