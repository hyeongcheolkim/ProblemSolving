import sys
from queue import Queue
from collections import defaultdict

SOLVED = "123456789"
SIZE = 3

puzzle = [list(sys.stdin.readline().replace("0", "9").strip().split(" "))[:SIZE] for _ in range(SIZE)]
init = "".join(e for inner in puzzle for e in inner)
q = Queue()
vst = defaultdict(int)
vst[init] = 0
q.put(init)
while not q.empty():
    now = q.get()
    if now == SOLVED:
        break
    idx = now.find("9")
    r, c = [idx // 3, idx % 3]
    for dr, dc in zip([0, 0, +1, -1], [+1, -1, 0, 0]):
        nr, nc = [r + dr, c + dc]
        if not (0 <= nr < 3 and 0 <= nc < 3):
            continue
        temp = now.replace(now[idx], "-").replace(now[nr * 3 + nc], now[idx]).replace("-", now[nr * 3 + nc])
        if not vst[temp]:
            vst[temp] = vst[now] + 1
            q.put(temp)
print(vst[SOLVED] if SOLVED in vst else -1)