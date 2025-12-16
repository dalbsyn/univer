#include<iostream>
#include<vector> // для vector
#include<ctime> // чтобы генератор случайных чисел генерировал случайные числа 
#include<random> // для mt19937
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
    const int n_rows = 4; // Заданное количество строк
    const int m_cols = 5; // Заданное количество столбцов
    double c1 = 0.0; // Нижняя граница интервала
    double c2 = 0.0; // Верхняя граница интервала
    int outside_count = 0; // Счетчик элементов вне интервала
    
    printf("Введите нижнюю границу интервала [c1]: ");
    cin >> c1;
    printf("Введите верхнюю границу интервала [c2]: ");
    cin >> c2;

    vector<vector<double>> matrix = double_matrix_gen(n_rows, m_cols, -20.0, 20.0);

    // Установка точности
    cout.setf(ios::fixed);
    cout.precision(2);

    printf("\nПолученная матрица (%i x %i):\n", n_rows, m_cols);

    for (int i = 0; i < n_rows; i++){
        for (int j = 0; j < m_cols; j++){
            cout << matrix[i][j] << "\t";

            // Проверка условия: элемент лежит вне интервала [c1, c2]
            if (matrix[i][j] < c1 || matrix[i][j] > c2){
                outside_count++;
            }
        }
        cout << endl;
    }
    
    printf("\nИнтервал для проверки: [%.2f, %.2f]\n", c1, c2);
    printf("Количество элементов матрицы, лежащих вне этого интервала: %i\n", outside_count);
}