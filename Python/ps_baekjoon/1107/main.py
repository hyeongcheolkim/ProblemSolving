#baekjoon ps 1107

n = int(input())
m = int(input())
res = abs(int(n)-100)
arr = []
if m!=0:
    arr = list(map(int, input().split(" ")))
if m==10:
    print(res)
    exit()
length = len(str(n))
for i in range(1000000+1):
    flag = True
    for j in str(i):
        if int(j) in arr:
            flag = False
            break
    if(flag):
        res = min(res,abs(n-i)+len(str(i)))
print(res)