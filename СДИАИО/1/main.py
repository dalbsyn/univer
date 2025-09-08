from PySide6.QtWidgets import (QApplication, QWidget, QTextEdit, QLabel,
                                QPushButton, QVBoxLayout, QMessageBox, 
                                QListWidget)


class Window(QWidget):
    def __init__(self):
        super().__init__()
        self.init_layout()
        self.init_widgets()
        self.place_widgets()
        self.connections()

    def init_layout(self):
        self.main_layout = QVBoxLayout()
        self.setLayout(self.main_layout)

    def init_widgets(self):
        self.label_input_list = QLabel('Входной лист')
        self.label_output_list = QLabel('Сортированный список')
        self.input_field = QTextEdit()
        self.output_box = QListWidget()
        self.sort_button = QPushButton('!СОРТИРОВАТЬ!')
    
    def place_widgets(self):
        self.main_layout.addWidget(self.label_input_list)
        self.main_layout.addWidget(self.input_field)
        self.main_layout.addWidget(self.label_output_list)
        self.main_layout.addWidget(self.output_box)
        self.main_layout.addWidget(self.sort_button)
    
    def connections(self):
        self.sort_button.clicked.connect(self.sort)

    def sort(self):
        # ТУТ ПРОВОДИТСЯ ИЗВЛЕЧЕНИЕ ТЕКСТА, ИЗ КОТОРОГО ИЗВЛЕКАЕТСЯ STRING ИЗ LINE.
        # ЗАТЕМ СЧИТАЕТСЯ КОЛИЧЕСТВО СТРОК (ОТЛАДКА).
        self.text: str = self.input_field.toPlainText()
        self.splitted_text = self.text.split('\n')
        self.line_amount = len(self.splitted_text)
        self.counter = 0
        self.line_dict = {}
        for i in self.splitted_text:
            self.counter += 1
            self.line_dict[i] = len(i.split())
            print(f"{self.counter} {i.split()} {len(i.split())}")
            self.output_box.addItem(i)
        print(self.line_dict)

app = QApplication()
window = Window()
window.show()
app.exec()