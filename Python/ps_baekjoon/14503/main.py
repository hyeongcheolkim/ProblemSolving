import sys

readline, write = (sys.stdin.readline, sys.stdout.write)
cnt = 0
robot = [0] * 2
dr = {
    0: [0, +1, 0, -1],
    1: [-1, 0, +1, 0],
    2: [0, -1, 0, +1],
    3: [+1, 0, -1, 0],
}
dc = {
    0: [-1, 0, +1, 0],
    1: [0, -1, 0, +1],
    2: [+1, 0, -1, 0],
    3: [0, +1, 0, -1],
}
n, m = map(int, readline().strip().split())
robot[0], robot[1], direction = map(int, readline().strip().split())
terrain = [list(map(int, readline().strip().split()))[:m] for i in range(n)]
vst = [[False] * m for i in range(n)]
vst[robot[0]][robot[1]] = True
cnt += 1
while True:
    r, c = robot
    flag = False
    for i in range(4):
        nr = r + dr[direction][i]
        nc = c + dc[direction][i]
        if not (0 <= nr < n and 0 <= nc < m) or terrain[nr][nc] == 1 or vst[nr][nc]:
            continue
        robot[0], robot[1] = nr, nc
        vst[nr][nc] = True
        cnt += 1
        turn = i + 1
        for _ in range(turn):
            direction -= 1
            direction = direction if direction >= 0 else 3
        flag = True
        break
    if not flag:
        nr = r + dr[direction][1]
        nc = c + dc[direction][1]
        if not (0 <= nr < n and 0 <= nc < m) or terrain[nr][nc] == 1:
            break
        robot[0], robot[1] = nr, nc
write(f"{cnt}")
