import sys

readline, write = (sys.stdin.readline, sys.stdout.write)

mxN = 250
dp = [0] * (mxN + 1)
dp[0] = 1
dp[1] = 1
dp[2] = 3
for i in range(3, mxN + 1):
    dp[i] = dp[i - 1] + dp[i - 2] * 2
res = [str(dp[int(n)]) for n in sys.stdin.readlines()]
write("\n".join(res))