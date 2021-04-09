# University of Seoul. Dept of Computer Science.
# 2018430021 김형철
# week6_04

for x in range(9,1,-1):
    print("|#%02d단#|"%x, end="")
print()

for i in range(9,0,-1):
    for j in range(9,1,-1):
        print("|%dX%d=%2d|"%(j,i,i*j),end="")
    print("")

