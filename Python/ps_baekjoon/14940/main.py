import sys
from queue import Queue

readline, write = (sys.stdin.readline, sys.stdout.write)
NOT_VST = -1
target = ()
q = Queue()
res = []

n, m = [int(i) for i in readline().split()]
board = [[int(i) for i in readline().split()][:m] for _ in range(n)]
vst = [[NOT_VST] * (m) for _ in range(n)]
for i in range(n):
    for j in range(m):
        if board[i][j] == 2:
            target = (i, j)
            vst[i][j] = 0
        if board[i][j] == 0:
            vst[i][j] = 0
q.put(target)
vst[target[0]][target[1]] = 0
while not q.empty():
    r, c = q.get()
    for dr, dc in zip((0, 0, +1, -1), (+1, -1, 0, 0)):
        nr = r + dr
        nc = c + dc
        if not (0 <= nr < n and 0 <= nc < m) or board[nr][nc] == 0:
            continue
        if vst[nr][nc] != NOT_VST:
            continue
        vst[nr][nc] = vst[r][c] + 1
        q.put((nr, nc))
for i in range(n):
    print(*vst[i])