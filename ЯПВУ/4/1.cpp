 #include<iostream>
 using namespace std;

 int visokos(int year){
    if (year % 4 == 0 && year % 100 != 0){
        // проверка делением на 400 без остатка не работает.
        // так хватает.
        return 366;
    }
    else{
        return 365;
    } 

 }

 int main(){
    int year;
    printf("Type year: ");
    wcin >> year;
    printf("In %d year = %d days.", year, visokos(year));
 }