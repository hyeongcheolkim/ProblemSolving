import sys

readline, write = (sys.stdin.readline, sys.stdout.write)

n = int(readline())


def hanoi(n=n, frm=1, via=2, to=3):
    if n == 1:
        write(f"{frm} {to}\n")
    else:
        hanoi(n - 1, frm, to, via)
        write(f"{frm} {to}\n")
        hanoi(n - 1, via, frm, to)


write(f"{2**n-1}\n")
if n <= 20:
    hanoi()