#include <iostream>
#include <thread>
using namespace std;

void tripple_bell(){
    int i;
    for (i = 1; i <= 3; i++){
        std::wcout.flush() << "\a";
        std::this_thread::sleep_for(500ms); 
    };
}
int main(){
    setlocale(LC_ALL, "");
    std::wcout << L"В чужбине свято наблюдаю" << std::endl;
    tripple_bell();
    std::wcout << L"Родной обычай старины:" << std::endl;
    tripple_bell();
    std::wcout << L"На волю птичку выпускаю" << std::endl;
    tripple_bell();
    std::wcout << L"При светлом празднике весны." << std::endl;
    tripple_bell();
}