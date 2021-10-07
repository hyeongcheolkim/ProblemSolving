import sys
from queue import Queue

readline, write = (sys.stdin.readline, sys.stdout.write)
mxN = 500
vst = [[False] * (mxN * 3 + 1) for _ in range(mxN * 3 + 1)]
q = Queue()


a, b, c = [int(i) for i in readline().split()]
total = a + b + c
if total % 3 != 0:
    write("0")
    exit(0)
q.put((a, b))
vst[a][b] = True
while not q.empty():
    a, b = q.get()
    c = total - a - b
    temp = (a, b, c)
    for i in range(3):
        for j in range(3):
            if temp[i] < temp[j]:
                num1 = temp[i] + temp[i]
                num2 = temp[j] - temp[i]
                if vst[num1][num2]:
                    continue
                vst[num1][num2] = True
                q.put((num1, num2))
write(f"{1 if vst[total//3][total//3] else 0}")