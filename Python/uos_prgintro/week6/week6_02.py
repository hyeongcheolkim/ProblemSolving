# University of Seoul. Dept of Computer Science.
# 2018430021 김형철
# week6_02

dan = int(input("단을 입력하세요:"))
for i in range(9,0,-1):
    print("{0:d} X {1:d} = {2:d}".format(i,dan,i*dan))