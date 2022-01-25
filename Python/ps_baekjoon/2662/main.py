import sys

sys.setrecursionlimit(10 ** 6)
readline, write = (sys.stdin.readline, sys.stdout.write)

n, m = [int(i) for i in readline().split()]
table = [[0] * (m + 1)] + [[0] + [int(i) for i in readline().split()][1 : m + 1] for _ in range(n)]
cache = [[-1] * (m + 1) for _ in range(n + 1)]
trace = [[0] * (m + 1) for _ in range(n + 1)]
res = []


def trace_company(cost=n, company=m):
    if company == 0:
        return
    trace_company(cost - trace[cost][company], company - 1)
    res.append(f"{trace[cost][company]} ")
    return


def solve(cost=n, company=m):
    if company == 0:
        return 0
    if cache[cost][company] != -1:
        return cache[cost][company]
    for k in range(cost + 1):
        value = solve(k, company - 1) + table[cost - k][company]
        if cache[cost][company] < value:
            cache[cost][company] = value
            trace[cost][company] = cost - k
    return cache[cost][company]


res.append(f"{solve()}\n")
trace_company()
write("".join(res))