# baekjoon ps 2407

import sys

(n, m) = list(map(int, sys.stdin.readline().split(" ")))
memo=[[0]*(n+1) for i in range(n+1)]
def c(a,b):
    if a==b or b==0:
        return 1
    if memo[a][b]!=0:
        return memo[a][b]
    else:
        memo[a][b] = c(a-1,b-1)+c(a-1,b)
        return memo[a][b]
print(c(n,m))
    
