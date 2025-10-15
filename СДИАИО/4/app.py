from PySide6.QtWidgets import *
import matplotlib.pyplot as plt
import networkx as nx
from matplotlib.backends.backend_qtagg import FigureCanvasQTAgg as FigureCanvas
import dijkstra


class DijkstraGraph(QWidget):
    def __init__(self):
        super().__init__()

        # Инициализация объекта графа
        self.figure = plt.figure()
        self.canvas = FigureCanvas(self.figure)

        self.main_layout = QGridLayout()
        self.setLayout(self.main_layout)
        self.main_layout.addWidget(self.canvas)
        
        self.ax = self.figure.add_subplot(111)
        self.ax.axis('off')
        
        self.figure.tight_layout()

    def clear_plot(self):
        self.ax.clear()
        self.ax.axis('off')
        self.canvas.draw()
        
    def plot_graph(self, graph_dict: dict, start_city, destination_city):
        self.clear_plot()

        shortest_path = dijkstra.dijkstra(graph_dict, start_city, destination_city)[1]

        G = nx.Graph(graph_dict)
        
        # Позиционирование вершин
        pos = nx.spring_layout(G, seed=1) 

        # Сбор весов ребер
        for city, neighbors in graph_dict.items():
            for neighbor, distance in neighbors.items():
                G.add_edge(city, neighbor, weight=distance)
        
        # Сами вершины
        nx.draw_networkx_nodes(G, pos, 
                        ax=self.ax, 
                        node_size=800, 
                        node_color='red', 
                        linewidths=1,
                        edgecolors='gray')
        
        # Сами ребра
        nx.draw_networkx_edges(G, pos, 
                               ax=self.ax,
                               width=2, 
                               edge_color='gray')
        
        # Названия вершин
        nx.draw_networkx_labels(G, pos, ax=self.ax, font_size=12, font_weight='bold')
        
        # Список весов ребер
        edge_labels = nx.get_edge_attributes(G, 'weight')
        
        # Подсветка кратчайшего пути
        shortest_path_edges = [(shortest_path[i], shortest_path[i + 1]) for i in range(len(shortest_path) - 1)]
        nx.draw_networkx_edges(G, pos, edgelist=shortest_path_edges, edge_color='red', width=2)

        # Веса у ребер
        nx.draw_networkx_edge_labels(G, pos, 
                        ax=self.ax, 
                        edge_labels=edge_labels, 
                        font_color='blue',
                        font_size=10)
        
        self.canvas.draw()


class InputGraph(QWidget):
    def __init__(self):
        super().__init__()

        # Инициализация объекта графа
        self.figure = plt.figure()
        self.canvas = FigureCanvas(self.figure)

        self.main_layout = QGridLayout()
        self.setLayout(self.main_layout)
        self.main_layout.addWidget(self.canvas)
        
        self.ax = self.figure.add_subplot(111)
        self.ax.axis('off')
        
        self.figure.tight_layout()

    def clear_plot(self):
        self.ax.clear()
        self.ax.axis('off')
        self.canvas.draw()
        
    def plot_graph(self, graph_dict: dict):
        self.clear_plot()
    
        G = nx.Graph(graph_dict, seed=1)
        
        # Позиционирование вершин
        pos = nx.spring_layout(G, seed=1) 

        # Сбор весов ребер
        for u, neighbors in graph_dict.items():
            for v, weight in neighbors.items():
                G.add_edge(u, v, weight=weight) 
        
        edge_labels = nx.get_edge_attributes(G, 'weight')

        # Сами вершины
        nx.draw_networkx_nodes(G, pos, 
                               ax=self.ax, 
                               node_size=800, 
                               node_color='red', 
                               linewidths=1,
                               edgecolors='gray')

        # Рёбра
        nx.draw_networkx_edges(G, pos, 
                               ax=self.ax,
                               width=2, 
                               edge_color='gray')
        

        # Метки вершин
        nx.draw_networkx_labels(G, pos, ax=self.ax, font_size=12, font_weight='bold')

        # Веса у ребер
        nx.draw_networkx_edge_labels(G, pos, 
                                     ax=self.ax, 
                                     edge_labels=edge_labels, 
                                     font_color='blue',
                                     font_size=10)

        self.canvas.draw()

class Graphs(QWidget):
    def __init__(self):
        super().__init__()

        self.init_layout()
        self.init_widgets()
        self.place_widgets()
    
    def init_layout(self):
        self.layout_main = QVBoxLayout()
        self.setLayout(self.layout_main)
    
    def init_widgets(self):
        self.input_graph = InputGraph()
        self.dijkstra_graph = DijkstraGraph()
    
    def place_widgets(self):
        self.layout_main.addWidget(self.input_graph)
        self.layout_main.addWidget(self.dijkstra_graph)


class Configure(QFormLayout):
    def __init__(self):
        super().__init__()

        self.init_widgets()
        self.place_widgets()
    
    def init_widgets(self):
        self.line = self.create_separator()
        self.title = self.title_label()
        self.row_amount = QLabel('Количество столбцов:')
        self.start_point = QLabel('Начальная вершина:')
        self.end_point = QLabel('Конечная вершина: ')
        self.spinbox_row_amount = QSpinBox(value=5)
        self.lineedit_start_point = self.widget_lineedit_start_point()
        self.lineedit_end_point = self.widget_lineedit_start_point()
        self.button_apply = QPushButton('Применить настройки')
        self.button_create = QPushButton('Построить граф')
    
    def place_widgets(self):
        self.addRow(self.line)
        self.addRow(self.title)
        self.addRow(self.start_point, self.lineedit_start_point)
        self.addRow(self.end_point, self.lineedit_end_point)
        self.addRow(self.row_amount, self.spinbox_row_amount)
        self.addRow(self.button_apply)
        self.addRow(self.button_create)
    
    def title_label(self):
        self.title = QLabel('Параметры')
        self.title.setStyleSheet('font-weight: bold; font-size: 24px;')
        return self.title
    
    def widget_lineedit_start_point(self):
        self.lineedit = QLineEdit()
        self.lineedit.setPlaceholderText('Например: A')
        return self.lineedit

    def get_row_amount(self):
        self.result = int(self.spinbox_row_amount.text())
        print(f'Configure.get_row_amount(): {self.result}')
        return self.result
    
    def get_current_points(self):
        self.start = self.lineedit_start_point.text()
        self.end = self.lineedit_end_point.text()
        print(f'Configure.get_current_points(): {self.start}, {self.end}')
        return [self.start, self.end]
    
    def create_separator(self):
        self.line = QFrame()
        self.line.setFrameShape(QFrame.Shape.HLine)
        self.line.setFrameShadow(QFrame.Shadow.Sunken)
        return self.line
        

class Table(QTableWidget):
    def __init__(self):

        super().__init__()

        self.init_table()
        self.name_columns()
     
    def init_table(self):
        self.setRowCount(5)
        self.setColumnCount(3)
    
    def name_columns(self):
        self.setHorizontalHeaderLabels(['Начало', 'Конец', 'Вес'])
    
    def change_row_amount(self, value):
        print(f'Table.change_row_amount(): смена количества срок на {value}')
        self.setRowCount(value)
    
    def get_matrix(self):
        self.row_count = self.rowCount()
        self.graph = {}

        for row in range(self.row_count):
            # Получение значений из таблицы в каждой строке
            self.start_item = self.item(row, 0)
            self.end_item = self.item(row, 1)
            self.weight_item = self.item(row, 2)
            
            if not self.start_item and not self.end_item and not self.weight_item:
                continue

            # Непосредственно для добавления в граф
            self.start_node = self.start_item.text().strip() if self.start_item else ""
            self.end_node = self.end_item.text().strip() if self.end_item else ""
            self.weight_str = self.weight_item.text().strip() if self.weight_item else ""

            print(f"Table.get_matrix(): self.start_node = {self.start_node}, self.end_node = {self.end_node}, self.weight_str = {self.weight_str}")

            if not self.start_node or not self.end_node or not self.weight_str:
                self.error_message("Начальный, конечный вершины или вес являются пустыми.")
            
            try:
                self.weight = int(self.weight_str)
                if self.weight < 0:
                    self.error_message("Вес не может быть отрицательным.")
                    continue
            except ValueError:
                self.error_message("Принимаются только целые значения.")
                print(f"Table.get_matrix(): преобразование не удалось, так как было передано вещественное число.")

            print(f"Table.get_matrix(): преобразование self.weight из str в int: {self.weight}")
                
            self.graph.setdefault(self.start_node, {})[self.end_node] = self.weight
            self.graph.setdefault(self.end_node, {})[self.start_node] = self.weight

            print(f"Table.get_matrix(): граф: {self.graph}")

        return self.graph
        
    def error_message(self, text):
        self.message = QMessageBox(text = text)
        self.message.setIcon(QMessageBox.Icon.Warning)
        self.message.show()


class MainWindow(QWidget):
    def __init__(self):
        super().__init__()

        self.showMaximized()

        self.init__ui()
        self.init_widgets()
        self.place_widgets()
        self.connections()
    
    def init__ui(self):
        self.layout_main = QGridLayout()
        self.setLayout(self.layout_main)
    
    def init_widgets(self):
        self.table = Table()
        self.configure = Configure()
        self.graphs = Graphs()
    
    def place_widgets(self):
        self.layout_main.addWidget(self.table, 0, 0)
        self.layout_main.addLayout(self.configure, 1, 0)
        self.layout_main.addWidget(self.graphs, 0, 1, 2, 1)
    
    def connections(self):
        self.configure.button_apply.clicked.connect(self.apply_configuration)
        self.configure.button_create.clicked.connect(self.dijkstra)

    def apply_configuration(self):
        self.result = self.configure.get_row_amount()
        self.table.change_row_amount(self.result)
    
    def dijkstra(self):
        self.graph = self.table.get_matrix()
        self.current_points = self.configure.get_current_points()
        print(f"Текущий граф: {self.graph}\nНачальная вершина: {self.current_points[0]}\nКонечная вершина: {self.current_points[1]}")
        if self.graph == {}:
            self.error_message("Пустой граф.")
        elif self.current_points[0] == "" or self.current_points[1] == "":
            self.error_message("Отстутсвует начальная или конечная (или обе) вершины.")
        else:
            self.graphs.input_graph.plot_graph(self.graph)
            self.graphs.dijkstra_graph.plot_graph(self.graph, self.current_points[0], self.current_points[1])

    def error_message(self, text):
        self.message = QMessageBox(text = text)
        self.message.setIcon(QMessageBox.Icon.Warning)
        self.message.show()

app = QApplication()
window = MainWindow()
window.show()
app.exec()