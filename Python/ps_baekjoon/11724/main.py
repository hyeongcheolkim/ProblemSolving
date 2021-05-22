# baekjoon ps 11724

import sys
import queue

n, m = map(int, input().split(" "))
cnt = 0
data = [[] for i in range(n + 1)]
check = [False for i in range(n + 1)]
for _ in range(m):
    a, b = map(int, input().split(" "))
    data[a].append(b)
    data[b].append(a)
q = queue.Queue()
for i in range(1,n+1):
    if not check[i]:
        q.put(i)
        cnt+=1
        check[i] = True
    while not q.empty():
        for i in data[q.get()]:
            if not check[i]:
                q.put(i)
                check[i] = True
print(cnt)
