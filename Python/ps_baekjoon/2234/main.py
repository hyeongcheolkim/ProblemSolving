import sys
from queue import Queue
from collections import defaultdict

readline, write = (sys.stdin.readline, sys.stdout.write)
q = Queue()
room = {}

n, m = [int(i) for i in readline().split()]
board = [[int(i) for i in readline().split()][:n] for _ in range(m)]
graph = defaultdict(set)
vst = [[0] * (n) for _ in range(m)]
index = 1
for i in range(m):
    for j in range(n):
        if not vst[i][j]:
            vst[i][j] = index
            cnt = 1
            q.put((i, j))
            while not q.empty():
                r, c = q.get()
                for dr, dc, movable in zip([0, +1, 0, -1], [+1, 0, -1, 0], [1, 2, 4, 8]):
                    nr = r + dr
                    nc = c + dc
                    if not (0 <= nr < m and 0 <= nc < n):
                        continue
                    if board[nr][nc] & movable:
                        if vst[nr][nc] and vst[nr][nc] != index:
                            graph[index].add(vst[nr][nc])
                        continue
                    if vst[nr][nc]:
                        continue
                    vst[nr][nc] = index
                    q.put((nr, nc))
                    cnt += 1
            room[index] = cnt
            index += 1
maxi = max([room[t[0]] + room[t[1]] for t in [(key, val) for key in graph for val in graph[key]]])
write(f"{len(room)}\n{max(room.values())}\n{maxi}")