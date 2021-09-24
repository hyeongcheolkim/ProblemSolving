import sys

readline, write = (sys.stdin.readline, sys.stdout.write)
res = []

t = int(readline())
for _ in range(t):
    n = int(readline())
    costs = list(map(int, readline().strip().split(" ")))[:n]
    total = int(readline())
    dp = [1] + [0] * (total)
    for cost in costs:
        for i in range(cost, total + 1):
            dp[i] += dp[i - cost]
    res.append(dp[total])
write("\n".join(str(i) for i in res))