# University of Seoul. Dept of Computer Science.
# 2018430021 김형철
# week6_05

sum = 0

num1 = int(input("시작값을 입력하세요 : "))
num2 = int(input("끝값을 입력하세요 : "))
num3 = int(input("증가값을 입력하세요 : "))

temp = num1

while(num1<=num2):
    sum +=num1
    num1+=num3
print("%d에서 %d까지 %d씩 증가시킨 값의 합계:%d"%(temp,num2,num3,sum))
