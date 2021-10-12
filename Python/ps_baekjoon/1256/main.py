import sys

readline, write = (sys.stdin.readline, sys.stdout.write)
res = []


def fnc(a, z):
    if dp[a][z] != -1:
        return dp[a][z]
    if a == 0 or z == 0:
        dp[a][z] = 1
        return 1
    dp[a][z] = fnc(a - 1, z) + fnc(a, z - 1)
    return dp[a][z]


n, m, k = [int(i) for i in readline().split()]
dp = [[-1] * (m + 1) for _ in range(n + 1)]
fnc(n, m)

if dp[n][m] < k:
    write("-1")
else:
    while True:
        if n == 0 or m == 0:
            res.append("z" * m)
            res.append("a" * n)
            break
        if k <= dp[n - 1][m]:
            res.append("a")
            n -= 1
        else:
            res.append("z")
            k -= dp[n - 1][m]
            m -= 1
write("".join(res))