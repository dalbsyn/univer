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
    const int matrix_size = 6;
    int special_count = 0; // Счетчик особых элементов
    
    vector<vector<int>> matrix = int_matrix_gen(matrix_size, -10, 10);

    printf("Полученная матрица (%i x %i):\n", matrix_size, matrix_size);

    // Вывод матрицы
    for (int i = 0; i < matrix_size; i++){
        for (int j = 0; j < matrix_size; j++){
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
    printf("\nИндексы [строка, столбец] \"особых\" элементов:\n");

    for (int j = 0; j < matrix_size; j++){
        int total_col_sum = 0; // Общая сумма элементов в текущем столбце
        
        // нахождение общей суммы элементов текущего столбца
        for (int i = 0; i < matrix_size; i++){
            total_col_sum += matrix[i][j];
        }

        // проверка каждого элемента столбца на особенность
        for (int i = 0; i < matrix_size; i++){
            // Условие: элемент больше суммы остальных элементов столбца.
            if (2 * matrix[i][j] > total_col_sum){
                special_count++;
                printf("[%i, %i]\n", i, j);
            }
        }
    }

    printf("\nОбщее количество \"особых\" элементов в массиве: %i\n", special_count);
}