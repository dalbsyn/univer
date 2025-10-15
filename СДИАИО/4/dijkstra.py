import heapq
import networkx as nx
import matplotlib.pyplot as plt
 
def dijkstra(graph, start, end):
    # Initialize distances dictionary
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
     
    # Initialize priority queue
    pq = [(0, start)]
     
    # Initialize previous node dictionary to store shortest path
    previous = {}
     
    while pq:
        current_distance, current_node = heapq.heappop(pq)
         
        # If we already found a shorter path to the current node, skip
        if current_distance > distances[current_node]:
            continue
         
        # Stop if we reached the destination
        if current_node == end:
            break
         
        # Explore neighbors
        for neighbor, distance in graph[current_node].items():
            new_distance = current_distance + distance
            if new_distance < distances[neighbor]:
                distances[neighbor] = new_distance
                heapq.heappush(pq, (new_distance, neighbor))
                previous[neighbor] = current_node
     
    # Reconstruct the shortest path
    path = []
    node = end
    while node != start:
        path.append(node)
        node = previous[node]
    path.append(start)
    path.reverse()
     
    return distances[end], path