#include <iostream>
#include <thread>
using namespace std;

int main(){
    setlocale(LC_ALL, "");
    std::wcout << L"Remember when you were young? \a" << std::endl;
    std::this_thread::sleep_for(500ms);
    std::wcout << L"\tYou shone like the Sun \a" << std::endl;
    std::this_thread::sleep_for(500ms);
    std::wcout << L"\t\tShine on, you crazy diamond \a" << std::endl;
    std::this_thread::sleep_for(500ms);
    std::wcout << L"\t\t\tNow there's a look in your eyes \a" << std::endl;
    std::this_thread::sleep_for(500ms);
    std::wcout << L"\t\t\t\tLike black holes in the sky \a" << std::endl;
    std::this_thread::sleep_for(500ms);
    std::wcout << L"\t\t\t\t\tShine on, you crazy diamond \a" << std::endl;
    std::this_thread::sleep_for(500ms);
    std::wcout << L"- Pink Floyd, 1975" << std::endl;
}