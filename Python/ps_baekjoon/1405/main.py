import sys

sys.setrecursionlimit(10**6)
readline, write = (sys.stdin.readline, sys.stdout.write)
SIZE = 30
total_case = 0
board = [[False] * SIZE for _ in range(SIZE)]


def dfs(r=SIZE // 2, c=SIZE // 2, level=0, case=1):
    global total_case, n, p
    if level == n:
        total_case += case
        return
    for dr, dc, p in zip([0, 0, +1, -1], [+1, -1, 0, 0], possibility):
        nr = r + dr
        nc = c + dc
        if board[nr][nc]:
            continue
        board[nr][nc] = True
        dfs(nr, nc, level + 1, case * p)
        board[nr][nc] = False


n, *possibility = [int(i) for i in readline().split()][:5]
board[SIZE // 2][SIZE // 2] = True
dfs()
res = total_case / 100 ** n
write(f"{res}")