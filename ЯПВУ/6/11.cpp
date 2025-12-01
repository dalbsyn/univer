#include<iostream>
#include<random>
#include<ctime>
using namespace std;

int main(){
    srand(time(0)); // инициализация случайного числа
    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int array_size = 1 + rand() % 256; // размер массива от 1 до 256
    char array[array_size];
    
    printf("Сгенерированные символы: ");
    for (int i = 0; i <= array_size; i++){
        // случайное число делю на количество символов, чтобы определить
        // допустимые рамки, в которых будет происходить перебор символов
        int rand_letter = rand() % letters.size();
        char letter = letters[rand_letter];
        array[i] = letter;

        cout << letter;
    }

    printf("\nБуквы до первой встречи С: ");
    for (int i = 0; i <= array_size; i++){
        char letter = array[i];
        // ASCII K = 75
        if(letter == 67){
            break;
        }
        cout << letter;
    }

    
}