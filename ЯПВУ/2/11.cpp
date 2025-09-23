#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "");
    std::wcout << L"+---------------------+-------------------------------------------------+" << std::endl;
    std::wcout << L"|      Simvol         |    Opisanie                                     |" << std::endl;
    std::wcout << L"+---------------------+-------------------------------------------------+" << std::endl;
    std::wcout << L"|     \\n              |       Perehod  no novuyu stroku                 |" << std::endl;
    std::wcout << L"+---------------------+-------------------------------------------------+" << std::endl;
    std::wcout << L"|     \\r              |       Vozvrat karretki                          |" << std::endl;
    std::wcout << L"+---------------------+-------------------------------------------------+" << std::endl;
    std::wcout << L"|     \\a              |       Podacha zvukovogo signala                 |" << std::endl;
    std::wcout << L"+---------------------+-------------------------------------------------+" << std::endl;
    std::wcout << L"|     \\b              |       Zateret odin simvol                       |" << std::endl;
    std::wcout << L"+---------------------+-------------------------------------------------+" << std::endl;
    std::wcout << L"|     \\t              |       Tabulacia                                 |" << std::endl;
    std::wcout << L"+---------------------+-------------------------------------------------+" << std::endl;
    std::wcout << L"|     \\               |       Vivod  \                                   |" << std::endl;
    std::wcout << L"+---------------------+-------------------------------------------------+" << std::endl;
    std::wcout << L"|     \\’              |       Vivod \\’                                  |" << std::endl;
    std::wcout << L"+---------------------+-------------------------------------------------+" << std::endl;
    std::wcout << L"|     \\”              |       Vivod \\”                                  |" << std::endl;
    std::wcout << L"+---------------------+-------------------------------------------------+" << std::endl;
}
