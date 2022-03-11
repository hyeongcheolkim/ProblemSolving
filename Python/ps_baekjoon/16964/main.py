import sys
from queue import Queue
from collections import deque

sys.setrecursionlimit(10**6)
readline, write = (sys.stdin.readline, sys.stdout.write)

n = int(readline())
graph = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    frm, to = [int(i) for i in readline().split()]
    graph[frm].append(to)
    graph[to].append(frm)
order = Queue()
order.queue = deque([int(i) for i in readline().split()])
vst = [False] * (n + 1)


def print_zero_and_exit():
    write("0")
    exit(0)


def trace(now_node):
    next_nodes = set()
    for next_node in graph[now_node]:
        if vst[next_node]:
            continue
        vst[next_node] = True
        next_nodes.add(next_node)
    while next_nodes:
        next_node = order.queue[0]
        if next_node in next_nodes:
            order.get()
            next_nodes.remove(next_node)
            trace(next_node)
        else:
            print_zero_and_exit()


if order.queue[0] != 1:
    print_zero_and_exit()
vst[1] = True
order.get()
trace(1)
write("1")
