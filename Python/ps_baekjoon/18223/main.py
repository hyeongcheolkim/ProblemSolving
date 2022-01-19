import sys
from queue import PriorityQueue

readline, write = (sys.stdin.readline, sys.stdout.write)
pq = PriorityQueue()
v, e, p = [int(i) for i in readline().split()]
graph = [[] for _ in range(v + 1)]


def min_dist(start, end):
    pq.put((0, start))
    dist = [float("inf")] * (v + 1)
    dist[start] = 0
    while not pq.empty():
        now_cost, now = pq.get()
        if dist[now] < now_cost:
            continue
        for next_cost, next in graph[now]:
            if now_cost + next_cost < dist[next]:
                dist[next] = now_cost + next_cost
                pq.put((dist[next], next))
    return dist[end]


for _ in range(e):
    frm, to, cost = [int(i) for i in readline().split()]
    graph[frm].append((cost, to))
    graph[to].append((cost, frm))
write("SAVE HIM" if min_dist(1, v) == min_dist(1, p) + min_dist(p, v) else "GOOD BYE")