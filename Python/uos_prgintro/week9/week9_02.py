# University of Seoul. Dept of Computer Science.
# 2018430021 김형철
# week9_02

string="<<<파<<이>>썬>>>"
for i in range(len(string)):
    if string[i]!='<' and string[i]!='>':
        print(string[i],end='')