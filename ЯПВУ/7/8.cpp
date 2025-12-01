#include<iostream>
#include<vector>
#include<ctime>
#include<random>
#include<algorithm> // для sort
using namespace std;

vector<int> int_array_gen(int length, int start, int end){
    // инициализация генератора случайных значений Мерсенна-Твистера и
    // задание диапазона генерируемых значений
    mt19937 mt(time(0));
    uniform_int_distribution<> distrib(start, end);
    vector<int> array;
    
    for (int i = 0; i < length; i++){
        int random_value = distrib(mt);
        array.push_back(random_value);
    }

    return array;
}

int main(){
    srand(time(0));
    int n = 21;

    vector<int> numbers = int_array_gen(n, -10, 10);
    vector<int> nechet;

    printf("Полученный массив чисел: ");

    for (int i = 0; i < n; i++){
        cout << numbers[i] << " ";
    }

    cout << endl;

    printf("Индексы и их значения:\n");

    for (int i = 0; i < n; i++){
        if (i % 2 != 0){
            nechet.push_back(numbers[i]);
            printf("%i - %i\n", i, numbers[i]);
        }
    }
    
    printf("Отсортированный массив нечетных по индексу чисел по возрастанию:");

    sort(nechet.begin(), nechet.end());

    for (int i = 0; i < nechet.size(); i++){
        cout << nechet[i] << " ";
    }
}