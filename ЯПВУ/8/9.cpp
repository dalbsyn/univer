#include<iostream>
#include<vector> // для vector
#include<ctime> // чтобы генератор случайных чисел генерировал случайные числа 
#include<random> // для mt19937
#include<iomanip> // для setprecision (вывод вещественных чисел)
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
    long long total_sum = 0; // Для накопления суммы
    double average_value = 0.0; // Среднее арифметическое
    
    printf("Введите количество строк N: ");
    cin >> n_rows;
    printf("Введите количество столбцов M: ");
    cin >> m_cols;

    // Генерация матрицы (целые числа, например, от -10 до 10)
    vector<vector<int>> matrix = int_matrix_gen(n_rows, m_cols, -10, 10);

    // Шаг 1: Вывод матрицы и подсчет общей суммы
    printf("\nПолученная матрица (%i x %i):\n", n_rows, m_cols);

    for (int i = 0; i < n_rows; i++){
        for (int j = 0; j < m_cols; j++){
            cout << matrix[i][j] << " ";
            total_sum += matrix[i][j];
        }
        cout << endl;
    }
    
    // Шаг 2: Расчет среднего арифметического
    int element_count = n_rows * m_cols;
    
    // Выполняем явное приведение типов для точного расчета среднего
    average_value = (double)total_sum / element_count;

    // Установка точности вывода для вещественных чисел
    cout.setf(ios::fixed);
    cout.precision(2);
    printf("\nСреднее арифметическое значение всех элементов: %.2f\n", average_value);

    // Шаг 3: Расчет и вывод отклонений от среднего
    printf("\nМатрица отклонений (Элемент - Среднее значение):\n");

    for (int i = 0; i < n_rows; i++){
        for (int j = 0; j < m_cols; j++){
            // Отклонение = A[i][j] - average_value
            double deviation = (double)matrix[i][j] - average_value;
            cout << deviation << " ";
        }
        cout << endl;
    }
}