import sys

readline, write = (sys.stdin.readline, sys.stdout.write)

n, t = [int(i) for i in readline().split()]
dp = [0] * (t + 1)
for _ in range(n):
    k, s = [int(i) for i in readline().split()]
    for i in range(t, k - 1, -1):
        dp[i] = max(dp[i], dp[i - k] + s)
write(f"{dp[t]}")
