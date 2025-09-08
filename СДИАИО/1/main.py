from PySide6.QtWidgets import (QApplication, QWidget, QTextEdit, QLabel,
                                QPushButton, QVBoxLayout, QMessageBox, 
                                QComboBox, QTableWidget, QTableWidgetItem)
import algo

class Window(QWidget):
    def __init__(self):
        """Инициализация интерфейса программы.
        """
        super().__init__()
        self.init_layout()
        self.init_widgets()
        self.place_widgets()
        self.connections()
        self.fill_selector()

    def init_layout(self):
        """Инициализация макета интерфейса
        """
        self.main_layout = QVBoxLayout()
        self.setLayout(self.main_layout)

    def init_widgets(self):
        """Инициализация всех виджетов
        """
        self.label_input_list = QLabel('Входной лист')
        self.label_output_list = QLabel('Сортированный список')
        self.label_type_selector = QLabel('Вариант сортировки')
        self.input_field = QTextEdit()
        self.output_box = QTableWidget(100, 2)
        self.sort_button = QPushButton('!СОРТИРОВАТЬ!')
        self.type_selector = QComboBox()
    
    def place_widgets(self):
        """Расположение виджетов на макете
        """
        self.main_layout.addWidget(self.label_input_list)
        self.main_layout.addWidget(self.input_field)
        self.main_layout.addWidget(self.label_output_list)
        self.main_layout.addWidget(self.output_box)
        self.main_layout.addWidget(self.label_type_selector)
        self.main_layout.addWidget(self.type_selector)
        self.main_layout.addWidget(self.sort_button)
    
    def connections(self):
        """Инициализация триггеров на действия от элементов интерфейса
        """
        self.sort_button.clicked.connect(self.sort)
    
    def fill_selector(self):
        """Заполнение выпадающего меню вариантами выбора сортировки
        """
        self.sort_types = ['По убыванию', 'По возрастанию']
        self.type_selector.addItem('Выберите тут вариант сортировки')
        self.type_selector.addItems(self.sort_types)

    def sort(self):
        """Сама реализация сортировки.

        
        """
        if self.sort_type() == 0:
            QMessageBox(text=f"Выберите следующие допустимые варианты сортировки:\n{self.sort_types}.").exec()
        else:
            print(f"ТЕКУЩИЙ ВАРИАНТ СОРТИРОВКИ: {self.type_selector.currentText()}")
            self.output_box.clear()
            self.text = self.input_field.toPlainText()
            self.sorted = algo.sort(self.text, self.sort_type())
            print(f"ИСХОДНЫЙ ТЕКСТ: {self.text}")
            print(f"СОРТИРОВАННЫЙ ТЕКСТ {self.sorted}")
            self.counter = 0
            """Ниже дичайший костыль, чтобы vscode не ныл, что с типом значения
            чтот-то не так. Вообще, все так. Вроде бы.
            """
            assert self.sorted
            for i in self.sorted:
                print(f"FOR I IN {self.sorted}, {i[0]}, {i[1]}")
                # self.output_box.addItem(i[0])
                self.output_box.setItem(self.counter, 0, QTableWidgetItem(i[0]))
                self.output_box.setItem(self.counter, 1, QTableWidgetItem(str(i[1])))
                self.counter += 1
    
    def sort_type(self):
        """Функция проверки текущего варианта порядка сортировки.

        Возвращает 0, если текущее значение не находится в списке 
        self.sort_types. Иначе - ничего не возвращает.
        """
        self.current_type = self.type_selector.currentText()
        if self.current_type not in self.sort_types:
            print(f"ТЕКУЩИЙ ВАРИАНТ СОРТИРОВКИ НЕ ЯВЛЯЕТСЯ ВАЛИДНЫМ: {self.current_type}")
            return 0
        elif self.current_type == "По убыванию":
            print(f"ТЕКУЩИЙ ВАРИАНТ СОРТИРОВКИ ЯВЛЯЕТСЯ ВАЛИДНЫМ: {self.current_type}. Будет <")
            return "<"
        elif self.current_type == "По возрастанию":
            print(f"ТЕКУЩИЙ ВАРИАНТ СОРТИРОВКИ ЯВЛЯЕТСЯ ВАЛИДНЫМ: {self.current_type}. Будет >")
            return ">"

app = QApplication()
window = Window()
window.show()
app.exec()