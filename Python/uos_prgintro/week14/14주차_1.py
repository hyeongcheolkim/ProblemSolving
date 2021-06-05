# University of Seoul. Dept of Computer Science.
# 2018430021 김형철
# week14_01

import os

inFp = open(
    os.path.dirname(os.path.realpath(__file__)) + "/" + "data1.txt",
    "r",
    encoding="UTF8",
)

num = 0
while True:
    num+=1
    string = inFp.readline()
    if string == "":
        break
    print(str(num) + ": " + string, end="")
inFp.close()