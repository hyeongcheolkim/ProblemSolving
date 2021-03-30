# University of Seoul. Dept of Computer Science.
# 2018430021 김형철
# week4_01

money = int(input("지폐로 교환할 돈은 얼마?"))

print("50000원짜리\t===> %d장" % int(money/50000))
money %= 50000

print("10000원짜리\t===> %d장" % int(money/10000))
money %= 10000

print("5000원짜리\t===> %d장" % int(money/5000))
money %= 5000

print("1000원짜리\t===> %d장" % int(money/1000))
money %= 1000

print("지폐로 바꾸지 못한 돈\t===> %d원" % money)



