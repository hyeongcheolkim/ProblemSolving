# University of Seoul. Dept of Computer Science.
# 2018430021 김형철
# week6_03

for i in range(2,10,1):
    print("## %02d단 ##"%i)
    for j in range(1,10,1):
        print("%d X %d = %2d" % (i,j,i*j))
    print("")