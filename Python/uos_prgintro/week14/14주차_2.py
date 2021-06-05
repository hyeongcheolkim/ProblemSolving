# University of Seoul. Dept of Computer Science.
# 2018430021 김형철
# week14_02

import os

inFp = open(
    os.path.dirname(os.path.realpath(__file__)) + "/" + "data1.txt",
    "r",
    encoding="UTF8",
)

strings = inFp.readlines()
for i in range(0, 3):
    print(str(i + 1) + ": " + strings[i], end="")
inFp.close()