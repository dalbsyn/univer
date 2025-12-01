#include <iostream>
#include <string>
using namespace std;

void frame(int x, int width, int height) {
    // инициализация пустого пространства перед рамкой
    std::string probel(x, ' ');

    // строка для верхней и нижней рамки вместе с пустым пространством
    std::string horizontal_line = probel + std::string(width, '+');

    // строка для боковых границ с пустым содержимым
    std::string middle_content = "+";
    if (width > 2) {
        middle_content += std::string(width - 2, ' ');
    }
    // правая граница будет, если ширина больше 1
    if (width > 1) {
        middle_content += "+";
    }
    std::string middle_line = probel + middle_content;


    // верхняя граница
    std::cout << horizontal_line << std::endl;

    // боковые границы
    if (height > 1) {
        // ограничение hieght -2, так как два поля уже заняты верхней и
        // нижней границами
        for (int i = 0; i < height - 2; ++i) {
            std::cout << middle_line << std::endl;
        }

        // нижняя граница, если высота больше 1
        if (height > 1) {
            std::cout << horizontal_line << std::endl;
        }
    }
}

int main() {
    std::cout << "[1] ----" << endl;
    frame(5, 10, 5);

    std::cout << "[2] ----" << endl;
    frame(10, 16, 4);

    std::cout << "[3] ----" << endl;
    frame(0, 20, 6);

    return 0;
}