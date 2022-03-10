import sys
from queue import PriorityQueue

readline, write = (sys.stdin.readline, sys.stdout.write)

n, v, e = [int(i) for i in readline().split()]
A, B = [int(i) for i in readline().split()]
members = [int(i) for i in readline().split()]
graph = [[] for _ in range(v + 1)]
res = 0


def min_distance(start_node):
    dist = [float("INF") for _ in range(v + 1)]
    pq = PriorityQueue()
    pq.put((0, start_node))
    dist[start_node] = 0
    while not pq.empty():
        in_cost, now_node = pq.get()
        in_cost = in_cost
        if dist[now_node] < in_cost:
            continue
        for out_cost, next_node in graph[now_node]:
            if (next_cost := in_cost + out_cost) < dist[next_node]:
                dist[next_node] = next_cost
                pq.put((next_cost, next_node))
    dist = [i if i != float("INF") else -1 for i in dist]
    return dist


for _ in range(e):
    a, b, l = [int(i) for i in readline().split()]
    graph[a].append((l, b))
    graph[b].append((l, a))
min_distance_A = min_distance(A)
min_distance_B = min_distance(B)
for member in members:
    res += min_distance_A[member] + min_distance_B[member]
write(f"{res}")
