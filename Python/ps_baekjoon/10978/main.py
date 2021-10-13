import sys

readline, write = (sys.stdin.readline, sys.stdout.write)
mxN = 20
cache = [0] * (mxN + 1)
res = []

cache[1] = 0
cache[2] = 1
for i in range(3, mxN + 1):
    cache[i] = (i - 1) * (cache[i - 1] + cache[i - 2])
for _ in range(int(readline())):
    res.append(cache[int(readline())])
write("\n".join(str(i) for i in res))