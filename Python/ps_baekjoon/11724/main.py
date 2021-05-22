# baekjoon ps 11724

import queue
import sys
n, m = map(int, sys.stdin.readline().split(" "))
cnt = 0
data = [[] for i in range(n + 1)]
check = [False for i in range(n + 1)]
q = queue.Queue()
for _ in range(m):
    a, b = map(int, sys.stdin.readline().split(" "))
    data[a].append(b)
    data[b].append(a)
for i in range(1,n+1):
    if not check[i]:
        q.put(i)
        cnt+=1
        check[i] = True
    while not q.empty():
        fn = q.get()
        for e in data[fn]:
            if not check[e]:
                q.put(e)
                check[e] = True
print(cnt)
