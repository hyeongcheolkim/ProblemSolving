import sys

sys.setrecursionlimit(10**6)
readline, write = (sys.stdin.readline, sys.stdout.write)
MOD = 1000000
pw = [0] + [int(i) for i in readline().strip()]
dp = [-1] * len(pw)


def solve(idx):
    if idx == 0:
        dp[0] = 1
        return dp[0]
    if dp[idx] != -1:
        return dp[idx]
    dp[idx] = 0
    pre_val = pw[idx - 1]
    now_val = pw[idx]
    if now_val != 0:
        dp[idx] = (dp[idx] + solve(idx - 1)) % MOD
    if 10 <= pre_val * 10 + now_val <= 26:
        dp[idx] = (dp[idx] + solve(idx - 2)) % MOD
    return dp[idx]


write(f"{solve(len(pw)-1)}")