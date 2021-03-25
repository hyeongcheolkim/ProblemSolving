# University of Seoul. Dept of Computer Science.
# 2018430021 김형철
# week4_02




## <전역 변수 부분> ##

#전역으로 year변수를 선언하고 0으로 초기화함.
year = 0  


## <메인 코드 부분> ##

#이 모듈이 직접실행되었을경우에만 if __name__ == "__main__": 다음을 실행한다. import될 경우 실행X
if __name__ == "__main__":

    #연도를 입력받고 int로 변환
    year = int(input("연도를 입력하세요 :"))

    #(year가 4로 나눠지고 year가 100으로 나눠떨어지지 않을때) 또는 (year가 400으로 나눠질때.)
    #이때 and가 or보다 연산 우선순위가 높으므로 A and B or C에서 (A and B) or (C)처럼 작동한다.
    if((year%4==0) and (year%100!=0) or (year%400==0)):
        print("%d년은 윤년입니다." % year)
    #조건이 false일 경우에 else이하 실행.
    else:
        print("%d년은 윤년이 아닙니다." % year)
