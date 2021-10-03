import sys
from queue import PriorityQueue

readline, write = (sys.stdin.readline, sys.stdout.write)
pq = PriorityQueue()
uf = []
vst = []
res = 0


def find(num) -> int:
    if num == uf[num]:
        return num
    if vst[num]:
        vst[uf[num]] = True
    uf[num] = find(uf[num])
    return uf[num]


def uni(a, b) -> bool:
    a, b = find(a), find(b)
    if a != b:
        if vst[a] and vst[b]:
            return False
        if vst[a] ^ vst[b]:
            vst[a], vst[b] = [True] * 2
        uf[a] = b
        return True
    else:
        return False


n, m, k = map(int, readline().split())
plant = [int(i) for i in readline().split()][:k]
uf = [i for i in range(n + 1)]
vst = [True] + [False for _ in range(n)]
for e in plant:
    vst[e] = True
for _ in range(m):
    u, v, w = map(int, readline().split())
    pq.put((w, u, v))
while not pq.empty() and not all(vst):
    cost, vertex1, vertex2 = pq.get()
    if uni(vertex1, vertex2):
        res += cost
write(f"{res}")