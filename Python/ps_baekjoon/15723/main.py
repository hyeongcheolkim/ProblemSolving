import sys

readline, write = (sys.stdin.readline, sys.stdout.write)
mxN = 26
graph = [[False] * (mxN + 1) for _ in range(mxN + 1)]
res = []

n = int(readline())
for _ in range(n):
    frm, to = [ord(e.strip()) - ord("a") + 1 for e in [str(i) for i in readline().strip().split("is")]]
    graph[frm][to] = True
for k in range(1, mxN + 1):
    for i in range(1, mxN + 1):
        for j in range(1, mxN + 1):
            graph[i][j] |= graph[i][k] & graph[k][j]
m = int(readline())
for _ in range(m):
    frm, to = [ord(e.strip()) - ord("a") + 1 for e in [str(i) for i in readline().strip().split("is")]]
    res.append("T\n" if graph[frm][to] else "F\n")
write("".join(res))