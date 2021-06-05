# University of Seoul. Dept of Computer Science.
# 2018430021 김형철
# week14_04
import os


source = input("소스 파일명을 입력하세요: ")
target = input("타깃 파일명을 입력하세요: ")

sourcefile = open(
    os.path.dirname(os.path.realpath(__file__)) + "/" + source + ".txt",
    "r",
    encoding="UTF8",
)
targetfile = open(
    os.path.dirname(os.path.realpath(__file__)) + "/" + target + ".txt",
    "w",
    encoding="UTF8",
)

strings = sourcefile.readlines()
for string in strings:
    targetfile.writelines(string)
sourcefile.close()
targetfile.close()
print("--- 파일이 정상적으로 복사되었음 ---")
