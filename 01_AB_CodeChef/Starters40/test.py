import numpy as np


# function to create adjacency list with weights
def make_graph(n, edges):
    graph = [[] for _ in range(n)]
    for u, v, w in edges:
        graph[u].append((v, w))
        graph[v].append((u, w))
    return graph


def shortestJourney(n, edges):
    graph = make_graph(n, edges)
    # perform bfs to get shortest path in which all nodes are visited
    visited = [False] * n
    dist = [float('inf')] * n
    dist[0] = 0
    queue = [0]
    while queue:
        u = queue.pop(0)
        visited[u] = True
        for v, w in graph[u]:
            if not visited[v]:
                dist[v] = min(dist[v], dist[u] + w)
                queue.append(v)
    # check if all nodes are visited
    if not all(visited):
        return -1
    # return the minimum distance
    return min(dist)


print(shortestJourney(4, [[0, 1, 1], [1, 2, 2], [1, 3, 3]]))
