#include <iostream>
#include <cmath>
using namespace std;

int minutes(float time){
    return floor(time);
}

int seconds(float time){
    double f;
    return modf(time, &f) * 100;
}

double velocity(float dist, float sec){
    return (dist / sec) * 3.6;
}
int main(){
    setlocale(LC_ALL, "");
    float distance, time;
    int time_seconds;
    wcout << L"Вычисление скорости бега." << endl;
    wcout << L"Введите длину дистанции (метров) -> ";
    wcin >> distance;
    wcout << L"Введите время (минут.секунд)-> ";
    wcin >> time;
    time_seconds = minutes(time) * 60 + seconds(time);
    wcout << L"Дистанция: " << distance << endl;
    wcout << L"Время: " << minutes(time) << L" мин " << seconds(time) << L" сек = " << time_seconds << L" сек" << endl;
    wcout << L"Вы бежали со скоростью " << velocity(distance, time_seconds) << L" км/час" << endl;
}