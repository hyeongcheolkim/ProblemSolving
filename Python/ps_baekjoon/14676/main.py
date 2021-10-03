import sys

readline, write = (sys.stdin.readline, sys.stdout.write)

n, m, k = [int(i) for i in readline().split()]
degree = [0] * (n + 1)
ea = [0] * (n + 1)
graph = [[] for _ in range(n + 1)]
for _ in range(m):
    frm, to = [int(i) for i in readline().split()]
    graph[frm].append(to)
    degree[to] += 1
for _ in range(k):
    opt, num = [int(i) for i in readline().split()]
    if opt == 1:
        if degree[num] == 0:
            if ea[num] == 0:
                for e in graph[num]:
                    degree[e] -= 1
            ea[num] += 1
        else:
            write("Lier!")
            exit(0)
    elif opt == 2:
        ea[num] -= 1
        if ea[num] < 0:
            write("Lier!")
            exit(0)
        if ea[num] == 0:
            for e in graph[num]:
                degree[e] += 1
write("King-God-Emperor")