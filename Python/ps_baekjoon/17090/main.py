import sys

sys.setrecursionlimit(10 ** 9)
readline, write = (sys.stdin.readline, sys.stdout.write)
direction = {"U": (-1, 0), "R": (0, +1), "D": (+1, 0), "L": (0, -1)}
cnt = 0
out_of_bound = 0
not_visit = -1


def dfs(row, col) -> bool:
    if maze[row][col] == out_of_bound:
        return True
    if cache[row][col] != not_visit:
        return cache[row][col]
    cache[row][col] = False
    dr, dc = direction[maze[row][col]]
    cache[row][col] = dfs(row + dr, col + dc)
    return cache[row][col]


n, m = map(int, readline().strip().split(" "))
maze = [[out_of_bound] * (m + 2) for _ in range(n + 2)]
for i in range(1, n + 1):
    maze[i][1 : m + 1] = [*list(readline().strip())[:m]]
cache = [[not_visit] * (m + 2) for _ in range(n + 2)]
for i in range(1, n + 1):
    for j in range(1, m + 1):
        if dfs(i, j):
            cnt += 1
write(f"{cnt}")