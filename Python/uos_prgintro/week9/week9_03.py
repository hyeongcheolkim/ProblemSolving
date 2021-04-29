# University of Seoul. Dept of Computer Science.
# 2018430021 김형철
# week9_03

string=input("문자열 입력 : ")
if string.isdigit():
    print("숫자입니다")
elif string.isalpha():
    print("글자입니다")
elif string.isalnum():
    print("글자+숫자입니다")
else:
    print("모르겠습니다")