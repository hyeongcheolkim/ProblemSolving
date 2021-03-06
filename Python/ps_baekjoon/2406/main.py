import sys

sys.setrecursionlimit(10 ** 6)
readline, write = (sys.stdin.readline, sys.stdout.write)
edges = []
res = []
x = 0


def find(num) -> int:
    if uf[num] == num:
        return num
    uf[num] = find(uf[num])
    return uf[num]


def uni(a, b) -> bool:
    a, b = find(a), find(b)
    if a != b:
        uf[b] = a
        return True
    return False


n, m = [int(i) for i in readline().split()]
uf = [i for i in range(n + 1)]
for _ in range(m):
    uni(*[int(i) for i in readline().split()])
graph = [0] + [[0] + [int(i) for i in readline().split()] for _ in range(n)][:n]
for i in range(1, n + 1):
    for j in range(1, n + 1):
        if i == j or i == 1 or j == 1:
            continue
        edges.append((graph[i][j], i, j))
edges.sort()
for edge in edges:
    cost, vertex1, vertex2 = edge
    if uni(vertex1, vertex2):
        x += cost
        res.append((vertex1, vertex2))
write(f"{x} {len(res)}\n")
for e in res:
    vertex1, vertex2 = e
    write(f"{vertex1} {vertex2}\n")