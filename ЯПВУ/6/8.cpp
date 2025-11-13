#include<iostream>
#include<sstream> //для stringstream
#include<string>
#include<vector> // для векторов
using namespace std;

int main(){
    // Было решено использовать векторы, так как для этой задачи требуется
    // массив произвольной величины. 
    vector<int> rosts = {};
    int input = 1;
    int wi = 0;
    float sred = 0;
    int prevysh = 0;

    printf("***АНАЛИЗ РОСТА УЧЕНИКОВ***\nВведите рост (см) и нажмите <Enter>.\nДля завершения введите 0 и нажмите <Enter>\n");

    // Ввод значений в массив
    while(input != 0){
        cout << "-> ";
        cin >> input;
        rosts.push_back(input);
        wi++;
    }

    // Поиск суммы роста 
    for (int i = 0; i < rosts.size(); i++){
        sred += rosts[i];
    }

    // Высчитывание среднего значения роста. У количества значений требуется
    // отнять 1, так как введенный 0 тоже считается, но он не нуженю.
    sred = sred / (rosts.size()-1);

    printf("Средний рост: %.1f см.\n", sred);

    // Поиск количества превышающих средний рост. 
    for (int i = 0; i < rosts.size(); i++){
        if (rosts[i] > sred){
            ++prevysh;
        }
    }

    printf("У %i человек рост превышает средний.\n", prevysh);
}
