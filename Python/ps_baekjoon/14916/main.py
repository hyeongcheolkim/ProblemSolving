import sys

readline, write = (sys.stdin.readline, sys.stdout.write)

n = int(readline())
max_five = n // 5
for i in range(max_five, -1, -1):
    remain = n - i * 5
    if remain % 2 == 0:
        write(f"{i + remain//2}")
        exit(0)
write("-1")