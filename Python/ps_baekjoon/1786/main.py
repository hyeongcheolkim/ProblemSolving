import sys

readline, write = (sys.stdin.readline, sys.stdout.write)
res = []

t, p = readline().rstrip(), readline().rstrip()
t_len, p_len = len(t), len(p)
dp = [0] * p_len
j = 0
for i in range(1, p_len):
    while j > 0 and p[i] != p[j]:
        j = dp[j - 1]
    if p[i] == p[j]:
        dp[i] = j + 1
        j += 1
j = 0
for i in range(t_len):
    while j > 0 and t[i] != p[j]:
        j = dp[j - 1]
    if t[i] == p[j]:
        if j + 1 == p_len:
            res.append(i - p_len + 1 + 1)
            j = dp[j]
        else:
            j += 1
write(f"{len(res)}\n")
write(" ".join([str(i) for i in res]))