#include<iostream>
#include<string>
using namespace std;

string sotnya (int number){
    // Получение сотни
    int result = number / 100;
    switch (result) {
        case 1:
            return "εκατό";
            break;
        case 2:
            return "διακόσια";
            break;
        case 3:
            return "τριακόσια";
            break;
        case 4:
            return "τετρακόσια";
            break;
        case 5:
            return "πεντακόσια";
            break;
        case 6:
            return "εξακόσια";
            break;
        case 7:
            return "εφτακόσια";
            break;
        case 8:
            return "οχτακόσια";
            break;
        case 9:
            return "εννιακόσια";
            break;
        default:
            return 0;
    }
}

string desyatok (int number){
    // Получение десятка
    int result = (number / 10) % 10;
    switch (result) {
        case 1:
            return "δέκα";
            break;
        case 2:
            return "είκοσι";
            break;
        case 3:
            return "τριάντα";
            break;
        case 4:
            return "σαράντα";
            break;
        case 5:
            return "πενήντα";
            break;
        case 6:
            return "εξήντα";
            break;
        case 7:
            return "εβδομήντα";
            break;
        case 8:
            return "ογδόντα";
            break;
        case 9:
            return "ενενήντα";
            break;
        default:
            return 0;
    }
}

string edinic (int number){
    // Получение единицы
    int result = number % 10;
    switch (result) {
        case 0:
            return "μηδέν";
            break;
        case 1:
            return "ένα";
            break;
        case 2:
            return "δύο";
            break;
        case 3:
            return "τρία";
            break;
        case 4:
            return "τέσσερα";
            break;
        case 5:
            return "πέντε";
            break;
        case 6:
            return "έξι";
            break;
        case 7:
            return "εφτά";
            break;
        case 8:
            return "οχτώ";
            break;
        case 9:
            return "εννιά";
            break;
        default:
            return 0;
    }
}

int main(){
    int number;
    
    cout << "Введите число: ";
    
    cin >> number;

    if (number / 100 != 0){
        // Проверка на наличие сотни
        cout << "Число " << number << " в греческой форме: " << sotnya(number) 
        << " " << desyatok(number) << " " << edinic(number); 
    } else if (number / 100 == 0 && ((number / 10)) % 10 != 0){
        // Проверка на наличие десятка, если нет сотни
        cout << "Число " << number << " в греческой форме: " << desyatok(number)
         << " " << edinic(number); 
    } else if ((number / 100 == 0 && ((number / 10)) % 10 == 0 && number % 10 != 0)){
        // Проверка на наличие единица, если нет сотни и десятка
        cout << "Число " << number << " в греческой форме: " << edinic(number); 
    } else {
        // ВСЁ
        cout << "Числа нет.";
    }
}