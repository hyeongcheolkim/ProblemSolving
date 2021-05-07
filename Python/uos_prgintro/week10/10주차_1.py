# University of Seoul. Dept of Computer Science.
# 2018430021 김형철
# week10_01

def coffee_machine(button, name):
    coffee={1:"아메리카노", 2:"카페라떼",3:"카푸치노",4:"에스프레소"}
    print()
    print("#1. (자동으로) 뜨거운 물을 준비한다.")
    print("#2. (자동으로) 종이컵을 준비한다.")
    print("#3. (자동으로) "+coffee[button]+"를 탄다.")
    print("#4. (자동으로) 물을 붓는다.")
    print("#5. (자동으로) 스푼으로 젓는다.")
    print(name+"씨~ 커피 여기 있습니다.")
customer = ["로제", "리사","지수","제니"]
for name in customer:
    button = int(input(name+"씨, 어떤 커피 드릴까요?(1:아메리카노, 2:카페라떼, 3:카푸치노, 4:에스프레소)"))
    coffee_machine(button, name)