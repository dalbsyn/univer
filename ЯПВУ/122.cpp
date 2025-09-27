#include<iostream>
using namespace std;

double kvadrat(double a, string type){
    double ploshad, perimetr;
    ploshad = a * a;
    perimetr = a + a;
    if (type == "p"){
        return perimetr;
    }
    else if (type == "s"){
        return ploshad;
    }
}

int main(){
    setlocale(LC_ALL, "");
    double a, perimetr, ploshad;
    wcout << L"Введите значение: " << endl;
    wcin >> a;
    perimetr = kvadrat(a, "p");
    ploshad = kvadrat(a, "s");
    wcout << L"Периметр: " << perimetr << endl;
    wcout << L"Площадь: " << ploshad << endl;
    if(perimetr > ploshad){
        wcout << L"Периметр больше площади" << endl;
    }
    else if(ploshad > perimetr){
        wcout << L"Площадь больше периметра" << endl;
    }
}