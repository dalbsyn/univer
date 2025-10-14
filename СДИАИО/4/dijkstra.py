import heapq
from math import inf

class DijkstraSolver:
    """
    Класс для выполнения алгоритма Дейкстры.
    """
    
    def __init__(self, graph: dict, start_node: str):
        """
        Инициализация решателя.
        
        Args:
            graph (dict): Словарь смежности графа.
            start_node (str): Начальная вершина.
        """
        self.graph = graph
        self.start_node = start_node
        self.distances = {}
        self.predecessors = {}

    def find_shortest_paths(self):
        """
        Выполняет алгоритм Дейкстры.
        
        Возвращает:
            tuple: (distances, predecessors)
        """
        # Инициализация расстояний и предшественников
        self.distances = {node: inf for node in self.graph}
        self.distances[self.start_node] = 0
        self.predecessors = {node: None for node in self.graph}
        
        priority_queue = [(0, self.start_node)]

        while priority_queue:
            current_distance, current_node = heapq.heappop(priority_queue)

            if current_distance > self.distances[current_node]:
                continue

            # Используем .get() с пустым словарем, чтобы избежать ошибки, 
            # если вершина есть в all_nodes, но не имеет исходящих ребер в графе
            for neighbor, weight in self.graph.get(current_node, {}).items():
                distance = current_distance + weight

                # Релаксация: Если найден более короткий путь
                if distance < self.distances[neighbor]:
                    self.distances[neighbor] = distance
                    self.predecessors[neighbor] = current_node 
                    heapq.heappush(priority_queue, (distance, neighbor))

        return self.distances, self.predecessors
    
    def reconstruct_path(self, target_node: str):
        """
        Восстанавливает кратчайший путь от начала до target_node.
        
        Args:
            target_node (str): Конечная вершина.
            
        Возвращает:
            str: Строка пути, разделенная " -> ".
        """
        path = []
        current = target_node
        # Идем назад от конечной вершины к начальной с помощью словаря предшественников
        while current is not None:
            path.append(current)
            current = self.predecessors.get(current)
            
            # Дополнительная проверка, чтобы избежать зацикливания, хотя в Дейкстре это маловероятно
            if current in path and current != self.start_node:
                 break 
                 
        return " -> ".join(path[::-1]) # Разворачиваем и форматируем