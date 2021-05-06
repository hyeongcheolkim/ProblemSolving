# University of Seoul. Dept of Computer Science.
# 2018430021 김형철
# week10_02

def calc(v1, v2, op):
    if op =='+':
        return v1+v2
    elif op =='-':
        return v1-v2
    elif op =='*':
        return v1*v2
    elif op =='/':
        return v1/v2
    elif op =="**":
        return v1**v2

v1 = int(input("첫 번째 수를 입력하세요 : "))
op = input("계산을 입력하세요(+, -, *, /, **) : ")
v2 = int(input("두 번째 수를 입력하세요 : "))
if(op=='/' and v2==0 ):
    print("0으로는 나누면 안 됩니다.ㅠㅠ") 
else:
    print("## 계산기 : %d %s %d = %d"%(v1,op,v2,calc(v1,v2,op)))
