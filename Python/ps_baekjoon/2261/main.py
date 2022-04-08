import sys

readline, write = (sys.stdin.readline, sys.stdout.write)


def distance(a, b):
    return (a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2


def divide_and_conquer(left, right):
    size = right - left + 1
    mid = (left + right) // 2
    if size == 2:
        return distance(points[left], points[right])
    if size == 3:
        return min(
            distance(points[left], points[mid]),
            distance(points[mid], points[right]),
            distance(points[left], points[right]),
        )
    ret = min(divide_and_conquer(left, mid), divide_and_conquer(mid + 1, right))
    border_points = []
    border = (points[mid][0] + points[mid + 1][0]) // 2
    for i in range(left, right + 1):
        if (border - points[i][0]) ** 2 < ret:
            border_points.append(points[i])
    border_points.sort(key=lambda x: x[1])
    for i in range(0, len(border_points)):
        for j in range(i + 1, len(border_points)):
            if (border_points[i][1] - border_points[j][1]) ** 2 < ret:
                ret = min(ret, distance(border_points[i], border_points[j]))
            else:
                break
    return ret


n = int(readline())
points = [[int(i) for i in readline().split()] for _ in range(n)]
points.sort()
write(f"{divide_and_conquer(0, n - 1)}")