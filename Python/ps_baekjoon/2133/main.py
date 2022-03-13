import sys

readline, write = (sys.stdin.readline, sys.stdout.write)

n = int(readline())
dp = [-1] * (n + 1)

if n % 2 == 1:
    write("0")
    exit(0)
dp[0] = 1
dp[2] = 3
for i in range(2, n + 1, 2):
    dp[i] = dp[i - 2] * 3
    for j in range(i, 4 - 1, -2):
        dp[i] += dp[i - j] * 2
write(f"{dp[n]}")