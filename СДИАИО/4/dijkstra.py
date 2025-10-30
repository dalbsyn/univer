import heapq
 
def dijkstra(graph, start, end):
    '''
    Словарь хранения кратчайшего пути от начальной вершины до каждой.
    Все вершины изначально имеют бесконечный (неизвестный) вес.
    '''
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    print(f'dijkstra.distances = {distances}')
     
    '''
    Инициализация кучи - структуры данных, представляющей из себя бинарное
    дерево в линейном представлении. По умолчанию используется минимальная
    куча, в которой корень - минимальное число, что в данном случае особенно
    удобно, так как начальной вершиной является всегда 0, а остальные - 
    бесконечные, так как они неизвестны пока что.
    ''' 
    pq = [(0, start)]
     
    '''
    Словарь хранения предка для каждой вершины. Используется для 
    реконструкции пути.
    '''
    previous = {}
     
    while pq:
        '''
        Цикл поиска минимального расстояния между двумя вершинами. Отчасти, эта
        задача и решается с помощью введенной выше кучи.
        '''
        current_distance, current_node = heapq.heappop(pq)
         
        # Если уже был найден короткий путь, то пропускаем
        if current_distance > distances[current_node]:
            continue
         
        # Остановка, если достигли конца
        if current_node == end:
            break
         
        '''
        Сбор информации о соседних узлах.
        Сперва вычисляется состояние от текущего узла до соседнего узла.
        Если новое расстояние короче, чем текущее записанное, то расстояние
        обновляется и это же расстояние добавляется в кучу, и соседний узел
        становится предком.
        '''
        for neighbor, distance in graph[current_node].items():
            new_distance = current_distance + distance
            if new_distance < distances[neighbor]:
                distances[neighbor] = new_distance
                heapq.heappush(pq, (new_distance, neighbor))
                previous[neighbor] = current_node
     
    '''
    Реконструкция пути с помощью словаря previous.
    Так как путь получается от конца к началу, то полученный список 
    переворачивается.
    '''
    path = []
    node = end
    while node != start:
        path.append(node)
        node = previous[node]
    path.append(start)
    path.reverse()
     
    return distances[end], path 