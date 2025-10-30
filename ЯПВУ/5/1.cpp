#include <iostream>
#include <string>
#include <unistd.h> // для линекса

// Форматирование текста цветом с помощью ANSI-последовательностей, так как на
// линексе нет виндвос трюков с system("color 01")
enum class AnsiColor {
    BLACK   = 30, // Чёрный
    RED     = 31, // Красный
    GREEN   = 32, // Зелёный
    YELLOW  = 33, // Жёлтый
    BLUE    = 34, // Синий
    MAGENTA = 35, // Пурпурный
    CYAN    = 36, // Голубой
    WHITE   = 37  // Белый
};

void print_colored_message(const std::string& message, int color_code, int style) {
    // Удобная функция разукрашивания текста 
    std::cout << "\033[" << style << ";" << color_code << "m"
              << message
              << "\033[0m" // возврат к стандартному цвету
              << std::endl;
}

int main() {
    std::string message = "Мусин Абукадыр";
    int number = 16;

    for (int i = 0; i < number; ++i) {
        
        // Определение стиля цвета - обычный или яркий. Также в рамках ANSI.
        // Если i < 8, то стиль = 0 (Обычный).
        // Если i >= 8, то i/8 = 1, стиль = 1 (Яркий).
        int style = i / 8; // 0 или 1
        
        // Определение базового кода цвета (30-37)
        // Берется остаток от деления на 8 (i % 8). Это даст числа от 0 до 7.
        // Затем прибавляется 30, чтобы получить коды от 30 до 37.
        int base_color_index = i % 8; // 0..7

        // Преобразование int в enum
        int color_code = static_cast<int>(AnsiColor::BLACK) + base_color_index; // 30..37
        
        print_colored_message(message, color_code, style);
        sleep(1);

        // Очистка консоли по-линексовски
        system("clear");
    }
    
    return 0;
}