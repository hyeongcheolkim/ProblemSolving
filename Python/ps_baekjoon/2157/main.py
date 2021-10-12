import sys
from collections import defaultdict

readline, write = (sys.stdin.readline, sys.stdout.write)

n, m, k = [int(i) for i in readline().split()]
graph = [defaultdict(int) for _ in range(n + 1)]
dp = [[None] + [0] + [-float("inf")] * (n - 1)] + [[-float("inf")] * (n + 1) for _ in range(m - 1)]
for _ in range(k):
    a, b, c = [int(i) for i in readline().split()]
    if not a < b:
        continue
    graph[a][b] = max(graph[a][b], c)
for frm in range(1, n + 1):
    for to, cost in graph[frm].items():
        for cnt in range(1, m):
            dp[cnt][to] = max(dp[cnt][to], dp[cnt - 1][frm] + cost)
write(f"{max([dp[i][n] for i in range(1, m)])}")