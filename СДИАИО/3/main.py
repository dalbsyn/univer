from PySide6.QtWidgets import (QWidget, QGridLayout, QTextBrowser, QPushButton,
                               QLabel, QApplication, QGroupBox, QFileDialog,
                               QMessageBox)
import algo

class Window(QWidget):
    def __init__(self):
        super().__init__()

        self.file_path = ""

        self.customize_window()
        self.init_layout()
        self.init_groupboxes()
        self.init_widgets()
        self.place_widgets()
        self.place_into_groupboxes()
        self.customize_label()
        self.connections()
    
    def init_layout(self):
        self.main_layout = QGridLayout()
        self.setLayout(self.main_layout)
    
    def init_groupboxes(self):
        self.gb_ro_textbox = QGroupBox('Область вывода результата: ')
        self.layout_gb_ro_textbox = QGridLayout()
        self.gb_ro_textbox.setLayout(self.layout_gb_ro_textbox)
    
    def init_widgets(self):
        self.main_label = QLabel("РАСПЕЧАТЫВАТЕЛЬ ТЕКСТА ОБРАТНЫЙ")
        self.read_only_textbox = QTextBrowser()
        self.label_file_path = QLabel("Путь к файлу: не выбран")
        self.button_select_file = QPushButton("Выбрать файл")
        self.make_button = QPushButton("!СДЕЛАТЬ!")
        self.explanation = QLabel("В праовй коробочке вводится текст, а в левой выводится текст в обратном порядке")
    
    def place_widgets(self):
        self.main_layout.addWidget(self.main_label, 0, 0, 1, 2)
        self.main_layout.addWidget(self.gb_ro_textbox, 1, 0, 1, 2)
        self.main_layout.addWidget(self.label_file_path, 2, 0, 1, 2)
        self.main_layout.addWidget(self.button_select_file, 3, 0, 1, 1)
        self.main_layout.addWidget(self.make_button, 3, 1, 1, 1)
        self.main_layout.addWidget(self.explanation, 4, 0, 1, 2)
    
    def place_into_groupboxes(self):
        self.layout_gb_ro_textbox.addWidget(self.read_only_textbox, 0, 0)
    
    def customize_window(self):
        self.setWindowTitle("РАСПЕЧАТЫВАТЕЛЬ ТЕКСТА ОБРАТНЫЙ")
    
    def customize_label(self):
        self.main_label.setStyleSheet('font-size: 20px; font-weight: bold;')
        self.explanation.setStyleSheet('font-size: 12px; font-weight: lighter;')
    
    def connections(self):
        self.button_select_file.clicked.connect(self.select_file)
        self.make_button.clicked.connect(self.make)
    
    def select_file(self):
        self.file_selector = QFileDialog()
        self.file_path = self.file_selector.getOpenFileName()[0]
        self.label_file_path.setText(f"Путь к файлу: {self.file_path}")
    
    def make(self):
        self.read_only_textbox.clear()
        self.words = algo.reverse_output_file(self.file_path)
        if self.words != 0:
            self.result = algo.output(self.words)
            self.read_only_textbox.setText(self.result)
        else:
            QMessageBox(text="""Вы не выбрали файл или выбранный файл является
двоичным, который невозможно считать.\nВыберите другой файл.""").exec()


app = QApplication()
window = Window()
window.show()
app.exec()