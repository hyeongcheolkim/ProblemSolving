import sys
from queue import LifoQueue

readline, write = (sys.stdin.readline, sys.stdout.write)
s = LifoQueue()
res = 0

h, w = [int(i) for i in readline().split()]
board = [[False] * (w + 1) for _ in range(h + 1)]
block = [None] + [int(i) for i in readline().split()]
for col in range(1, w + 1):
    for row in range(h - block[col] + 1, h + 1):
        board[row][col] = True
for row in range(h, 0, -1):
    s.queue.clear()
    for col in range(1, w + 1):
        if board[row][col]:
            if not s.empty():
                res += (col - s.get()) - 1
            s.put(col)
write(f"{res}")