import sys
from queue import PriorityQueue

readline, write = (sys.stdin.readline, sys.stdout.write)
pq = PriorityQueue()

n, m = [int(i) for i in readline().split()]
graph = [[] for _ in range(n + 1)]
dist = [float("inf")] * (n + 1)
for _ in range(m):
    frm, to, cost = [int(i) for i in readline().split()]
    graph[frm].append((cost, to))
    graph[to].append((cost, frm))
s, t = [int(i) for i in readline().split()]
dist[s] = 0
pq.put((0, s))
while not pq.empty():
    in_cost, now = pq.get()
    if dist[now] < in_cost:
        continue
    for out_cost, next in graph[now]:
        if (next_cost := in_cost + out_cost) < dist[next]:
            dist[next] = next_cost
            pq.put((next_cost, next))
write(f"{dist[t]}")