#include<iostream>
#include<vector> // для vector
#include<ctime> // чтобы генератор случайных чисел генерировал случайные числа 
#include<random> // для mt19937
#include<limits> // для инициализации max_value
#include<algorithm> // для swap
using namespace std;

// Функция генерации вещественной матрицы N x M
vector<vector<double>> double_matrix_gen(int n, int m, double start, double end){
    // инициализация генератора случайных значений Мерсенна-Твистера и
    // задание диапазона генерируемых значений
    mt19937 mt(time(0));
    // Используем uniform_real_distribution для вещественных чисел (double)
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
    const int n_rows = 7; // Заданное количество строк
    const int m_cols = 4; // Заданное количество столбцов
    // Инициализация max_value минимально возможным значением
    double max_value = numeric_limits<double>::lowest(); 
    int max_row = 0; // Индекс строки, содержащей максимальный элемент
    
    // Генерация матрицы (вещественные числа от -20.0 до 20.0)
    vector<vector<double>> matrix = double_matrix_gen(n_rows, m_cols, -20.0, 20.0);

    // Установка точности вывода для вещественных чисел
    cout.setf(ios::fixed);
    cout.precision(2);

    // Шаг 1: Вывод матрицы и поиск наибольшего элемента и его строки
    printf("Полученная исходная матрица (%i x %i):\n", n_rows, m_cols);

    for (int i = 0; i < n_rows; i++){
        for (int j = 0; j < m_cols; j++){
            cout << matrix[i][j] << " ";

            if (matrix[i][j] > max_value){
                // Обновление максимального значения и индекса строки
                max_value = matrix[i][j];
                max_row = i;
            }
        }
        cout << endl;
    }
    
    printf("\nНаибольший элемент в матрице: %.2f\n", max_value);
    printf("Обнаружен в строке (индекс с 0): %i\n", max_row);

    // Шаг 2: Обмен строки с максимальным элементом (max_row) с первой строкой (индекс 0)
    // Используем стандартную функцию std::swap для обмена векторами
    if (max_row != 0){
        swap(matrix[0], matrix[max_row]);
        printf("\nСтрока %i успешно обменяна с первой строкой.\n", max_row);
    } else {
        printf("\nМаксимальный элемент уже находится в первой строке. Обмен не требуется.\n");
    }

    // Шаг 3: Вывод измененной матрицы
    printf("\nМатрица после обмена:\n");
    for (int i = 0; i < n_rows; i++){
        for (int j = 0; j < m_cols; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}