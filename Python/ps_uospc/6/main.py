import sys

readline, write = (sys.stdin.readline, sys.stdout.write)

cnt = 0

s, t = [str(i) for i in readline().split()]
arr1 = [int(s, base) for base in range(int(max(s)) + 1, 10 + 1)]
arr2 = [int(t, base) for base in range(int(max(t)) + 1, 10 + 1)]
for i in arr1:
    for j in arr2:
        if i == j:
            cnt+=1
write(f"{cnt}")