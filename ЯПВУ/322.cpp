// ВАРИАНТ 10
#include<iostream>
using namespace std;

int f(int x){
    if(x % 2 != 0){
        return 0;
    }
    else{
        return x / 2;
    }
}

int main(){
    setlocale(LC_ALL, "");
    int x, result;
    wcout << L"Введите число: " << endl;
    wcin >> x;
    result = f(x);
    if (result == 0){
        wcout << L"Число нечетное: " << result;
    }
    else if(result != 0){
        wcout << L"Число четное: " << result;
    }

}