# University of Seoul. Dept of Computer Science.
# 2018430021 김형철
# week11_02

res = {}
def fibo(n):
    if(n==1):
        res[n] = 0
        return 0
    if(n==2):
        res[n] = 1
        return 1
    res[n]=fibo(n-1)+fibo(n-2)
    return res[n]
fibo(int(input("n을 입력하세요 fibo(n)출력:")))
print(sorted(list(res.values())))
    