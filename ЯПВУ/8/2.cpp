#include<iostream>
#include<vector> // для vector
#include<ctime> // чтобы генератор случайных чисел генерировал случайные числа 
#include<random> // для mt19937
#include<limits> // для инициализации max_value
using namespace std;

// Функция генерации вещественной матрицы N x M
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
    double max_value = numeric_limits<double>::lowest(); // Инициализация минимально возможным значением
    
    printf("Введите количество строк N: ");
    cin >> n_rows;
    printf("Введите количество столбцов M: ");
    cin >> m_cols;

    // Генерация матрицы (вещественные числа от -20.0 до 20.0)
    vector<vector<double>> matrix = double_matrix_gen(n_rows, m_cols, -20.0, 20.0);

    // Установка точности
    cout.setf(ios::fixed);
    cout.precision(2);

    printf("\nПолученная исходная матрица (%i x %i):\n", n_rows, m_cols);

    // Вывод исходной матрицы
    for (int i = 0; i < n_rows; i++){
        for (int j = 0; j < m_cols; j++){
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // Поиск максимального элемента в матрице
    for (int i = 0; i < n_rows; i++){
        for (int j = 0; j < m_cols; j++){
            if (matrix[i][j] > max_value){
                max_value = matrix[i][j];
            }
        }
    }
    
    printf("\nМаксимальный элемент в матрице: %.2f\n", max_value);

    // Замена всех отрицательных элементов на максимальный элемент
    for (int i = 0; i < n_rows; i++){
        for (int j = 0; j < m_cols; j++){
            if (matrix[i][j] < 0.0){
                matrix[i][j] = max_value;
            }
        }
    }

    printf("\nМатрица после замены отрицательных элементов на максимальный:\n");

    for (int i = 0; i < n_rows; i++){
        for (int j = 0; j < m_cols; j++){
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}