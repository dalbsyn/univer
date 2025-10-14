from PySide6.QtWidgets import *
import matplotlib.pyplot as plt
import networkx as nx
from matplotlib.backends.backend_qtagg import FigureCanvasQTAgg as FigureCanvas

import sys
import logging
from math import inf

from dijkstra import DijkstraSolver


class MplGraphWidget(QWidget):
    def __init__(self):
        super().__init__()

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
    
        G = nx.Graph(graph_dict)
        
        # 2. Определяем позиционирование вершин
        # 'spring_layout' - стандартный алгоритм для красивого расположения вершин
        pos = nx.spring_layout(G) 

        # 3. Получаем веса рёбер для отображения
        for u, neighbors in graph_dict.items():
            for v, weight in neighbors.items():
                # Добавляем ребро (u, v) с атрибутом weight
                # NetworkX автоматически обрабатывает симметричность для неориентированного графа
                # Но мы можем добавить только одну сторону, чтобы избежать дублирования
                G.add_edge(u, v, weight=weight) 
        
        edge_labels = nx.get_edge_attributes(G, 'weight')

        # 4. Рисуем вершины
        nx.draw_networkx_nodes(G, pos, 
                               ax=self.ax, 
                               node_size=800, 
                               node_color='red', 
                               linewidths=1,
                               edgecolors='gray')

        # 5. Рисуем рёбра
        nx.draw_networkx_edges(G, pos, 
                               ax=self.ax,
                               width=2, 
                               edge_color='gray')
        

        # 6. Рисуем метки вершин (имена A, B, C...)
        nx.draw_networkx_labels(G, pos, ax=self.ax, font_size=12, font_weight='bold')

        nx.draw_networkx_edge_labels(G, pos, 
                                     ax=self.ax, 
                                     edge_labels=edge_labels, 
                                     font_color='blue',
                                     font_size=10)

        # 8. Обновляем холст
        self.canvas.draw()


class DijkstraResultWidget(QWidget):
    """
    Виджет для встраивания графика Matplotlib, 
    специализированный для отображения результатов алгоритма Дейкстры 
    (расстояний и кратчайшего пути).
    """
    def __init__(self, parent=None):
        super().__init__(parent)
        
        # 1. Создаем объект Figure (сам график) и FigureCanvas (холст для Qt)
        self.figure = plt.figure()
        self.canvas = FigureCanvas(self.figure)
        
        # 2. Создаем макет и добавляем холст
        self.layout_main = QVBoxLayout(self)
        self.layout_main.addWidget(self.canvas)
        
        # 3. Добавляем subplots - оси, на которых будем рисовать
        self.ax = self.figure.add_subplot(111)
        self.ax.axis('off') # Скрываем оси x и y
        self.figure.tight_layout()

    def clear_plot(self):
        """Очищает текущий график."""
        self.ax.clear()
        self.ax.axis('off')
        self.canvas.draw()
        
    def plot_result(self, graph_dict: dict, distances: dict, predecessors: dict, start_node: str):
        """
        Строит граф, отображает кратчайшие расстояния и подсвечивает путь.
        """
        self.clear_plot()
        
        # 1. Создание графа NetworkX (Явное добавление рёбер для надежности!)
        G = nx.Graph() 
        for u, neighbors in graph_dict.items():
            for v, weight in neighbors.items():
                G.add_edge(u, v, weight=weight) 

        pos = nx.spring_layout(G, seed=42)
        edge_labels = nx.get_edge_attributes(G, 'weight')
        
        # 2. Обновление меток вершин: "Имя (Расстояние)"
        node_labels = {}
        for node, dist in distances.items():
            dist_str = '∞' if dist == inf else str(dist)
            node_labels[node] = f"{node}\n({dist_str})"

        # 3. Определение рёбер, лежащих на кратчайших путях (для подсветки)
        path_edges = set()
        for target_node in G.nodes():
             current = target_node
             while predecessors.get(current) is not None:
                 prev = predecessors[current]
                 # Добавляем ребро как отсортированный кортеж, чтобы учесть неориентированность
                 path_edges.add(tuple(sorted((prev, current))))
                 current = prev
        
        # 4. Рисуем узлы
        # Подсветка начальной вершины
        node_colors = ['#FFC300' if node == start_node else 'lightblue' for node in G.nodes()]
        
        nx.draw_networkx_nodes(G, pos, 
                               ax=self.ax, 
                               node_size=1000, 
                               node_color=node_colors, 
                               linewidths=1,
                               edgecolors='black')

        # 5. Рисуем рёбра с подсветкой
        default_edges = [e for e in G.edges() if tuple(sorted(e)) not in path_edges]
        highlight_path_edges = [e for e in G.edges() if tuple(sorted(e)) in path_edges]
        
        # Рисуем обычные рёбра (серым)
        nx.draw_networkx_edges(G, pos, edgelist=default_edges, ax=self.ax, width=1, edge_color='gray')

        # Рисуем рёбра кратчайшего пути (красным)
        nx.draw_networkx_edges(G, pos, edgelist=highlight_path_edges, ax=self.ax, width=3, edge_color='red')

        # 6. Рисуем метки вершин (с расстояниями)
        nx.draw_networkx_labels(G, pos, ax=self.ax, labels=node_labels, font_size=11, font_weight='bold')

        # 7. Рисуем метки рёбер (веса)
        nx.draw_networkx_edge_labels(G, pos, ax=self.ax, edge_labels=edge_labels, font_color='blue', font_size=10)

        self.canvas.draw()
        
class Graphs(QTabWidget):
    def __init__(self):
        super().__init__()

        self.init_tabs()
        self.create_tabs()
    
    def init_tabs(self):
        self.input_graph = MplGraphWidget()
        self.dijkstra_graph = DijkstraResultWidget()
    
    def create_tabs(self):
        self.addTab(self.input_graph, "Выходной граф")
        self.addTab(self.dijkstra_graph, "Кратчаший путь по алгоритму Дейкстры")


class Configure(QFormLayout):
    def __init__(self, logging_instance):
        super().__init__()

        self.logging_instance = logging_instance

        self.init_widgets()
        self.place_widgets()
    
    def init_widgets(self):
        self.line = self.create_separator()
        self.title = self.title_label()
        self.row_amount = QLabel('Количество столбцов:')
        self.start_point = QLabel('Начальная вершина:')
        self.spinbox_row_amount = QSpinBox(value=5)
        self.lineedit_start_point = self.widget_lineedit_start_point()
        self.button_apply = QPushButton('Применить настройки')
        self.button_create = QPushButton('Построить граф')
        self.button_dijkstra = QPushButton('Построить кратчаший путь')
    
    def place_widgets(self):
        self.addRow(self.line)
        self.addRow(self.title)
        self.addRow(self.start_point, self.lineedit_start_point)
        self.addRow(self.row_amount, self.spinbox_row_amount)
        self.addRow(self.button_apply)
        self.addRow(self.button_create, self.button_dijkstra)
    
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
        self.logging_instance.debug(f'Configure.get_row_amount(): {self.result}')
        return self.result
    
    def get_current_start_point(self):
        self.result = self.lineedit.text()
        self.logging_instance.debug(f'Configure.get_current_start_point(): {self.result}')
        return self.result
    
    def create_separator(self):
        self.line = QFrame()
        self.line.setFrameShape(QFrame.Shape.HLine)
        self.line.setFrameShadow(QFrame.Shadow.Sunken)
        return self.line
        


class Table(QTableWidget):
    def __init__(self, logging_instance):
        self.logging_instance = logging_instance

        super().__init__()

        self.init_table()
        self.name_columns()
     
    def init_table(self):
        self.setRowCount(5)
        self.setColumnCount(3)
    
    def name_columns(self):
        self.setHorizontalHeaderLabels(['Начало', 'Конец', 'Вес'])
    
    def change_row_amount(self, value):
        self.logging_instance.debug(f'Table.change_row_amount(): смена количества срок на {value}')
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

            self.logging_instance.debug(f"Table.get_matrix(): self.start_node = {self.start_node}, self.end_node = {self.end_node}, self.weight_str = {self.weight_str}")

            if not self.start_node or not self.end_node or not self.weight_str:
                self.error_message("Начальный, конечный вершины или вес являются пустыми.")
            
            try:
                self.weight = int(self.weight_str)
                if self.weight < 0:
                    self.error_message("Вес не может быть отрицательным.")
                    continue
            except ValueError:
                self.error_message("Принимаются только целые значения.")
                self.logging_instance.debug(f"Table.get_matrix(): преобразование не удалось, так как было передано вещественное число.")

            self.logging_instance.debug(f"Table.get_matrix(): преобразование self.weight из str в int: {self.weight}")
                
            self.graph.setdefault(self.start_node, {})[self.end_node] = self.weight
            self.graph.setdefault(self.end_node, {})[self.start_node] = self.weight

            self.logging_instance.debug(f"Table.get_matrix(): граф: {self.graph}, начальная вершина: {self.start_node}")

        return self.graph, self.start_node

        
    def error_message(self, text):
        self.message = QMessageBox(text = text)
        self.message.setIcon(QMessageBox.Icon.Warning)
        self.message.show()


class MainWindow(QWidget):
    def __init__(self, logging_instance):
        super().__init__()

        self.logging_instance = logging_instance
        self.logging_instance.debug('MainWindow.__init__(): окно создано')

        self.showMaximized()

        self.init__ui()
        self.init_widgets()
        self.place_widgets()
        self.connections()
    
    def init__ui(self):
        self.layout_main = QGridLayout()
        self.setLayout(self.layout_main)
    
    def init_widgets(self):
        self.table = Table(self.logging_instance)
        self.configure = Configure(self.logging_instance)
        self.graphs = Graphs()
    
    def place_widgets(self):
        self.layout_main.addWidget(self.table, 0, 0)
        self.layout_main.addLayout(self.configure, 1, 0)
        self.layout_main.addWidget(self.graphs, 0, 1, 2, 1)
    
    def connections(self):
        self.configure.button_apply.clicked.connect(self.apply_configuration)
        self.configure.button_create.clicked.connect(self.create_graph)
        self.configure.button_dijkstra.clicked.connect(self.dijkstra)

    def apply_configuration(self):
        self.result = self.configure.get_row_amount()
        self.table.change_row_amount(self.result)
    
    def create_graph(self):
        self.graph = self.table.get_matrix()[0]
        self.start_node = self.configure.get_current_start_point()
        self.graphs.input_graph.plot_graph(self.graph)
    
    def dijkstra(self):
        self.graph = self.table.get_matrix()[0]
        self.start_node = self.configure.get_current_start_point()
        self.dijkstra_solver = DijkstraSolver(self.graph, self.start_node)
        distances, predecessors = self.dijkstra_solver.find_shortest_paths()
        self.graphs.dijkstra_graph.plot_result(self.graph, distances, predecessors, self.start_node)


logger = logging.getLogger(__name__)
logging.basicConfig(stream=sys.stdout, level=logging.INFO)

app = QApplication()
window = MainWindow(logger)
window.show()
app.exec()

logging.debug('Приложение завершило работу')