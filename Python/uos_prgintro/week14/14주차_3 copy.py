# University of Seoul. Dept of Computer Science.
# 2018430021 김형철
# week14_03

import os

filename = input("파일명을 입력하세요(txt): ")
outFp = open(
    os.path.dirname(os.path.realpath(__file__)) + "/" + filename + ".txt",
    "w",
    encoding="UTF8",
)

while True:
    outStr = input("내용 입력: ")
    if outStr != "":
        outFp.writelines(outStr + "\n")
    else:
        break
outFp.close()
print("--- 정상적으로 파일에 씀 ---")
