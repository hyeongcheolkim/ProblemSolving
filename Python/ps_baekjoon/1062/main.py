import sys
from collections import defaultdict

readline, write = (sys.stdin.readline, sys.stdout.write)
exist = ["a", "n", "t", "i", "c"]
vst = defaultdict(bool)
res = 0

def count():
    cnt = 0
    for word in words:
        if all(map(lambda x: vst[x], word)):
            cnt += 1
    return cnt


def solve(cnt=5, init='a'):
    global res
    if cnt >= k:
        res = max(res, count())
        return
    for i in range(ord(init), ord("z") + 1):
        i = chr(i)
        if vst[i]:
            continue
        vst[i] = True
        solve(cnt + 1, chr(ord(init)+1))
        vst[i] = False
        
n, k = [int(i) for i in readline().split()]
words = [set(readline().rstrip()) for _ in range(n)]
for e in exist:
    vst[e] = True
solve()
write("{0}".format(res))
