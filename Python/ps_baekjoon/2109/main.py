import sys
from queue import PriorityQueue

readline, write = (sys.stdin.readline, sys.stdout.write)
pq = PriorityQueue()
res = 0


class lecture:
    __slots__ = ["pay", "day"]

    def __init__(self, pay, day):
        self.pay = pay
        self.day = day

    def __lt__(self, obj):
        return self.pay > obj.pay


n = int(readline())
lectures = [lecture(*[int(i) for i in readline().split()][:2]) for _ in range(n)]
lectures.sort(key=lambda x: x.day)
max_day = lectures[-1].day if lectures else 0
for today in range(max_day, 0, -1):
    while lectures and lectures[-1].day == today:
        pq.put(lectures.pop())
    if not pq.empty():
        res += pq.get().pay
write(f"{res}")
