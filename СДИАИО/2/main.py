import sys
from PySide6.QtWidgets import (QApplication, QVBoxLayout, QLineEdit, QWidget,
                               QPushButton, QTableWidget, QTableWidgetItem,
                               QLabel, QMessageBox)
import algo

class Window(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("ЗАГОЛОВИЧИЩЕ ОКНОШИЩА")
        self.init_layout()
        self.init_widgets()
        self.place_widgets()
        self.connections()
    
    def init_layout(self):
        self.main_layout = QVBoxLayout()
        self.setLayout(self.main_layout)
    
    def init_widgets(self):
        self.label_input_list = QLabel("Введите список чисел")
        self.label_warning = QLabel("!!!!!СОРТИРУЕТ ТОЛЬКО ПО ВОЗРАСТАНИБЮ!!!!!!!1")
        self.button = QPushButton("ПУКС")
        self.field_input = QLineEdit()
        self.table = QTableWidget(100, 2)
    
    def place_widgets(self):
        self.main_layout.addWidget(self.label_input_list)
        self.main_layout.addWidget(self.field_input)
        self.main_layout.addWidget(self.button)
        self.main_layout.addWidget(self.table)
        self.main_layout.addWidget(self.label_warning)
    
    def connections(self):
        self.button.clicked.connect(self.find_in_list)
    
    def find_in_list(self):
        self.parse_input()

    def parse_input(self):
        self.input = self.field_input.text()
        self.processed_input = algo.sort(self.input)
        if self.processed_input == 0:
            QMessageBox(text='''ОШИБКА: ВВОДИТЕ ТОЛЬКО ЧИСЛА.
НАРУЖЕНЫ НЕДОПУСТИМЫЕ СИМВОЛЫ (в т.ч. пробел).
НЕОБРАБАТЫВАЕМОЕ ИСКЛЮЧЕНИЕ.''').exec()
        print(self.processed_input)


app = QApplication(sys.argv)
window = Window()
window.show()
sys.exit(app.exec())