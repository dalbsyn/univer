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
    int n_size = 0; // Размерность матрицы
    int even_count = 0; // Счетчик четных элементов
    
    printf("Введите размерность N квадратной матрицы: ");
    cin >> n_size;

    vector<vector<int>> matrix = int_matrix_gen(n_size, -10, 10);

    printf("\nПолученная матрица (%i x %i):\n", n_size, n_size);

    for (int i = 0; i < n_size; i++){
        for (int j = 0; j < n_size; j++){
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
    // Поиск количества четных элементов выше главной диагонали (i < j)
    for (int i = 0; i < n_size; i++){
        for (int j = 0; j < n_size; j++){
            // Проверка условия расположения (выше главной диагонали)
            if (i < j){
                // Проверка условия значения (четный элемент)
                if (matrix[i][j] % 2 == 0){
                    even_count++;
                }
            }
        }
    }

    printf("\nКоличество четных элементов, расположенных выше главной диагонали: %i\n", even_count);
}