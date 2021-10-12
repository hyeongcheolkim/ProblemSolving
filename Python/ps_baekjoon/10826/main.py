import sys

sys.setrecursionlimit(10 ** 6)
readline, write = (sys.stdin.readline, sys.stdout.write)


def fibonacci(num) -> int:
    if cache[num] != -1:
        return cache[num]
    if num == 0:
        return 0
    if num == 1:
        return 1
    cache[num] = fibonacci(num - 1) + fibonacci(num - 2)
    return cache[num]


n = int(readline())
cache = [-1] * (n + 1)
write(f"{fibonacci(n)}")