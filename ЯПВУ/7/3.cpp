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
    bool changeto = false;

    vector<int> numbers = int_array_gen(n, -10, 10);
    vector<int> nechet;

    printf("Полученный массив чисел: ");

    for (int i = 0; i < n; i++){
        cout << numbers[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < n; i++){
        if (numbers[i] < -2){
            printf("Найден элемент со значением -2. Теперь, все отрицательные значения будут заменены на их квадраты.");
            changeto = true;
            break;
        }
    }
    
    for (int i = 0; i < n; i++){
        if (numbers[i] < 0 and changeto == true){
            numbers[i] = numbers[i] * numbers[i];
        }
    }

    cout << endl;

    printf("Массив чисел после решения задачи: ");

    for (int i = 0; i < n; i++){
        cout << numbers[i] << " ";
    }

}