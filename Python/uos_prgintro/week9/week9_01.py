# University of Seoul. Dept of Computer Science.
# 2018430021 김형철
# week9_01

string = "파이썬은완전재미있어요"
for i in range(len(string)):
    if i%2==0:
        print(string[i],end='')
    else:
        print('#',end='')