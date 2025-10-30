#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    double epsilon; 
    
    printf("Задайте точность вычисления ПИ -> ");
    
    if (!(cin >> epsilon) || epsilon <= 0) {
        fprintf(stderr, "Некорректный ввод точности. Программа завершена.\n");
        return 1;
    }

    // Целочисленное значение, с которым будем сравнивать n
    // Например, для epsilon=0.001, required_n_limit = 1 / 0.001 = 1000
    // Мы хотим, чтобы цикл продолжался, пока n <= 1003.
    // Если n > 1003, то 1/n < 1/1003, что заведомо меньше 0.001.
    // Устанавливаем лимит для знаменателя, который будет последним просуммированным.
    const int required_n_limit = 1003; 

    double pi_4 = 0.0;     
    long long count = 0;   
    int n = 1;             
    double term;           

    // Условие цикла: n должен быть меньше или равен требуемому пределу 1003
    while (n <= required_n_limit) { 
        
        term = 1.0 / n;

        if (count % 2 == 0) {
            pi_4 += term;
        } else {
            pi_4 -= term;
        }

        count++;

        // Увеличиваем знаменатель для следующего члена
        n += 2; 
    }

    double pi_result = 4.0 * pi_4;
    printf("Значение числа ПИ с точностью %g равно %.4f\n", epsilon, pi_result);
   
    printf("Просуммировано %lld члена ряда.\n", count);

    return 0;
}
