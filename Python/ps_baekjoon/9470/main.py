import sys
from queue import Queue

readline, write = (sys.stdin.readline, sys.stdout.write)
res = []

t = int(readline())
for _ in range(t):
    k, m, p = [int(i) for i in readline().split()]
    degree = [0] * (m + 1)
    graph = [[] * (m + 1) for _ in range(m + 1)]
    strahler = [[0, 0] for _ in range(m + 1)]
    q = Queue()
    maxi = 1
    for _ in range(p):
        a, b = [int(i) for i in readline().split()]
        graph[a].append(b)
        degree[b] += 1
    for i in range(1, m + 1):
        if degree[i] == 0:
            q.put(i)
            strahler[i] = [1, 1]
    while not q.empty():
        now = q.get()
        maxi = max(maxi, strahler[now][0])
        for edge in graph[now]:
            degree[edge] -= 1
            if strahler[edge][0] < strahler[now][0]:
                strahler[edge] = [strahler[now][0], 1]
            elif strahler[edge][0] == strahler[now][0]:
                strahler[edge][1] += 1
            if degree[edge] == 0:
                if strahler[edge][1] > 1:
                    strahler[edge] = [strahler[edge][0] + 1, 1]
                q.put(edge)
    res.append(f"{k} {maxi}")
write("\n".join(res))