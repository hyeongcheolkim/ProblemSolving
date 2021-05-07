# University of Seoul. Dept of Computer Science.
# 2018430021 김형철
# week10_03

def para_func(*args):
    return sum(i for i in args)

print(para_func(1,2))
print(para_func(1,2,3))
print(para_func(1,2,3,4,5,6,7,8,9,10))
