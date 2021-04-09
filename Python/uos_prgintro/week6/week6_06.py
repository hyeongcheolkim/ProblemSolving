# University of Seoul. Dept of Computer Science.
# 2018430021 김형철
# week6_06

while True:
    a = input("더할 첫 번째 수를 입력하세요($입력시 종료):")
    if a=='$':
        print("종료합니다.")
        break;
    b = int(input("더할 두 번째 수를 입력하세요 : "))
    print("%s + %d = %d"%(a,b,int(a)+b))
     