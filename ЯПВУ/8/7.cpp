#include<iostream>
#include<vector> // для vector
#include<ctime> // чтобы генератор случайных чисел генерировал случайные числа 
#include<random> // для mt19937
using namespace std;

// Функция генерации целочисленной квадратной матрицы
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
    long long total_sum = 0; // Для накопления суммы и предотвращения переполнения
    double average_value = 0.0; // Среднее арифметическое
    
    printf("Введите размерность N квадратной матрицы: ");
    cin >> matrix_size;

    // Генерация матрицы (целые числа, например, от -10 до 10)
    vector<vector<int>> matrix = int_matrix_gen(matrix_size, -10, 10);

    printf("\nПолученная исходная матрица (%i x %i):\n", matrix_size, matrix_size);

    // Вывод исходной матрицы и подсчет общей суммы
    for (int i = 0; i < matrix_size; i++){
        for (int j = 0; j < matrix_size; j++){
            cout << matrix[i][j] << " ";
            total_sum += matrix[i][j];
        }
        cout << endl;
    }
    
    // Шаг 1: Расчет среднего арифметического
    int element_count = matrix_size * matrix_size;
    
    // Выполняем явное приведение типов для точного расчета среднего
    average_value = (double)total_sum / element_count;

    // Вывод среднего значения с установкой точности
    cout.setf(ios::fixed);
    cout.precision(2);
    printf("\nСреднее арифметическое значение всех элементов: %.2f\n", average_value);

    // Шаг 2: Замена отрицательных элементов на среднее значение
    for (int i = 0; i < matrix_size; i++){
        for (int j = 0; j < matrix_size; j++){
            if (matrix[i][j] < 0){
                // Замена с усечением до целого числа
                matrix[i][j] = (int)average_value; 
            }
        }
    }

    printf("\nМатрица после замены отрицательных элементов на среднее (усеченное):\n");

    // Сбрасываем точность, чтобы целые числа выводились корректно (без .00)
    cout.unsetf(ios::fixed);
    cout.precision(6); 
    
    // Вывод измененной матрицы
    for (int i = 0; i < matrix_size; i++){
        for (int j = 0; j < matrix_size; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}