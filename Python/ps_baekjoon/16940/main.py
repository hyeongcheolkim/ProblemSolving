import sys
from queue import Queue
from collections import deque

readline, write = (sys.stdin.readline, sys.stdout.write)
q = Queue()
order = Queue()
n = int(readline())
graph = [[] for _ in range(n + 1)]
vst = [False] * (n + 1)


def print_zero_and_exit():
    write("0")
    exit(0)


for _ in range(n - 1):
    frm, to = [int(i) for i in readline().split()]
    graph[frm].append(to)
    graph[to].append(frm)
order.queue = deque([int(i) for i in readline().split()])
if order.queue[0] != 1:
    print_zero_and_exit()
q.put(1)
vst[1] = True
order.get()
while not q.empty():
    next_nodes = set()
    now_node = q.get()
    for next_node in graph[now_node]:
        if vst[next_node]:
            continue
        vst[next_node] = True
        next_nodes.add(next_node)
    for _ in range(len(next_nodes)):
        if order.empty():
            print_zero_and_exit()
        node = order.get()
        if node in next_nodes:
            q.put(node)
        else:
            print_zero_and_exit()
write("1")
