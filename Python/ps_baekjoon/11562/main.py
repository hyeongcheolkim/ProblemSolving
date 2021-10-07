import sys

readline, write = (sys.stdin.readline, sys.stdout.write)
res = []

n, m = [int(i) for i in readline().split()]
graph = [[float("inf")] * (n + 1) for _ in range(n + 1)]
for i in range(n + 1):
    graph[i][i] = 0
for _ in range(m):
    u, v, b = [int(i) for i in readline().split()]
    graph[u][v] = 0
    graph[v][u] = 0 if b else 1
for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])
k = int(readline())
for _ in range(k):
    s, e = [int(i) for i in readline().split()]
    res.append(f"{graph[s][e]}\n")
write("".join(i for i in res))