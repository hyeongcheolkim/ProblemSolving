import sys
from collections import defaultdict

readline, write = (sys.stdin.readline, sys.stdout.write)
coefficient = defaultdict(int)
res = 0

n = int(readline())
words = [readline().strip() for _ in range(n)]
for word in words:
    for idx, alphabet in enumerate(word):
        coefficient[alphabet] += 10 ** (len(word) - idx - 1)
coefficient = sorted(coefficient.items(), key=lambda x: x[1], reverse=True)
for (alphabet, coef), weight in zip(coefficient, range(9, 0, -1)):
    res += coef * weight
write(f"{res}")