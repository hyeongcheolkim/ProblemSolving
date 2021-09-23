import sys
from queue import PriorityQueue

sys.setrecursionlimit(10**9)
readline = sys.stdin.readline
write = sys.stdout.write
cnt = 0
total_cost = 0


def find(num) -> int:
    if uf[num] == num:
        return num
    uf[num] = find(uf[num])
    return uf[num]


def uni(a, b) -> bool:
    a, b = (find(a), find(b))
    if a != b:
        uf[a] = b
        return True
    return False


n = int(readline())
uf = [i for i in range(n + 1)]
pq = PriorityQueue()
graph = [[0] * (n + 1)] + [[0] + list(map(int, readline().strip().split(" ")))[:n] for _ in range(n)]
for i in range(1, n + 1):
    for j in range(1, n + 1):
        if i >= j:
            pq.put((graph[i][j], i, j))
while cnt != n - 1:
    cost, vertex1, vertex2 = pq.get()
    if uni(vertex1, vertex2):
        cnt += 1
        total_cost += cost
write(f"{total_cost}")