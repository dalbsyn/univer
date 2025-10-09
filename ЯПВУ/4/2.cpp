#include<iostream>
#include<iomanip>
using namespace std;

float get_kmh(float speed){
    // формула вычисления км/ч в м/c = скорость * 1000 / 3600.
    // так как 1000 / 3600 ~ 0.278, то используется эта константа.
    return speed * 0.278;
}

int get_result(float kmh, float ms){
    kmh = get_kmh(kmh);
    if (kmh > ms){
        return 1;
    } else if (kmh < ms){
        return 2;
    } else{
        return 3;
    }
}

int main(){
    float kmh, ms, kmh_in_ms;
    int result;

    printf("Введите скорость в км/ч: ");
    wcin >> kmh;
    printf("Введите скорость в м/c: ");
    wcin >> ms;

    kmh_in_ms = get_kmh(kmh);
    result = get_result(kmh, ms);

    if (result == 1){
        printf("Скорость в %.3f км/ч больше (%.3f м/c), чем %.3f м/c.", kmh, kmh_in_ms, ms);
    } else if (result == 2) {
        printf("Скорость в %.3f м/c больше, чем %.3f км/c (%.3f м/c).", ms, kmh, kmh_in_ms);
    } else if (result == 3){
        printf("Скорости равны (%.3f км/ч (%.3f м/с) = %.3f м/с).", kmh, kmh_in_ms, ms);
    }
}