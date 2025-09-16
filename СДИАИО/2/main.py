import sys
from PySide6.QtWidgets import (QApplication, QVBoxLayout, QLineEdit, QWidget,
                               QPushButton, QTableWidget, QTableWidgetItem,
                               QLabel, QMainWindow)
import algo

class Window(QWidget):
    """
    Класс для создания главного окна приложения "Наибольшая возрастающая подпоследовательность".
    """
    def __init__(self):
        super().__init__()
        self.setWindowTitle("TEST")
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
        self.list =  self.input.split(' ')
        self.int_list = []
        print(self.input)
        print(self.list)
        for i in self.list:
            self.int_list.append(int(i))
        print(self.int_list)
        algo.fund_subsequence(self.int_list)



app = QApplication(sys.argv)
window = Window()
window.show()
sys.exit(app.exec())