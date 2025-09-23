from PySide6.QtWidgets import (QApplication, QWidget, QLineEdit, QLabel,
                                QPushButton, QVBoxLayout, QMessageBox, 
                                QTableWidget, QTableWidgetItem)
from PySide6.QtGui import QColor
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
        self.customize_table()

    def init_layout(self):
        """Инициализация макета интерфейса
        """
        self.main_layout = QVBoxLayout()
        self.setLayout(self.main_layout)

    def init_widgets(self):
        """Инициализация всех виджетов
        """
        self.label_input_list = QLabel('Введите массив чисел')
        self.label_output_list = QLabel('Все найденные массивы чисел. Красным отмечается наибольшая подпоследовательность')
        self.input_field = QLineEdit()
        self.output_box = QTableWidget(200, 2)
        self.sort_button = QPushButton('!НАЙТИ!')
    
    def place_widgets(self):
        """Расположение виджетов на макете
        """
        self.main_layout.addWidget(self.label_input_list)
        self.main_layout.addWidget(self.input_field)
        self.main_layout.addWidget(self.label_output_list)
        self.main_layout.addWidget(self.output_box)
        self.main_layout.addWidget(self.sort_button)
    
    def connections(self):
        """Инициализация триггеров на действия от элементов интерфейса
        """
        self.sort_button.clicked.connect(self.solution)

    def solution(self):
        """Решение задачи
        """
        self.input = self.input_field.text()
        self.processed_input = algo.process_output(self.input)
        if self.processed_input == 0:
            QMessageBox(text='УБЕРИТЕ КАКИЕ-ЛИБО НЕ ЧИСЛА').exec()
        else:
            self.output_box.clear()
            self.fill_table(self.processed_input)
            self.add_longest(self.processed_input)
            self.color_row()
    
    def add_longest(self, list):
        """
        Добавление нвп
        """
        self.result = algo.find_longest_increasing_subsequence(list)
        print(f"Наибольшая подпоследовательность: {len(self.result)} - {self.result}")
        self.output_box.setItem(0, 0, QTableWidgetItem(str(len(self.result))))
        self.output_box.setItem(0, 1, QTableWidgetItem(str(self.result)))

    def fill_table(self, list):
        """
        Заполнение таблицы остальными подпоследовательностями
        """
        self.subseq = algo.find_all_increasing_subsequences(list)
        self.counter = 1
        for i in self.subseq:
            print(f"Добавляется подпоследовательность и количество элементов: {len(i)} - {i}")
            self.output_box.setItem(self.counter, 0, QTableWidgetItem(str(len(i))))
            self.output_box.setItem(self.counter, 1, QTableWidgetItem(str(i)))
            self.counter += 1
    
    def color_row(self):
        """
        Разукрашивание нвп
        """
        self.color: QColor = QColor("#FF2A2A")
        self.item0 = self.output_box.item(0, 0)
        self.item1 = self.output_box.item(0, 1)

        # Чтоб VSCode не ныл, что в нужной строке ничего нет (None).
        # Все там будет, поэтому пусть заткнется.
        assert self.item0
        assert self.item1

        self.item0.setBackground(self.color)
        self.item1.setBackground(self.color)
    
    def customize_table(self):
        self.output_box.setHorizontalHeaderLabels(['Количество элементов', 'Подпоследовательность'])
        self.output_box.resizeColumnsToContents()

app = QApplication()
window = Window()
window.show()
app.exec()