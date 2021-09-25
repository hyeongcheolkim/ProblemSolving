import sys
from queue import PriorityQueue

readline, write = (sys.stdin.readline, sys.stdout.write)
pq = PriorityQueue()
res = 0

n = int(readline())
arr = sorted([list(map(int, readline().strip().split(" ")))[:2] for _ in range(n)])
for i in range(arr[-1][0], 0, -1):
    while arr and arr[-1][0] == i:
        pq.put(-arr.pop()[1])
    if not pq.empty():
        res += -pq.get()
write(f"{res}")