//baekjoon 1427 ps

#include <stdio.h>

int main()
{
    char a;
    char str[10]= {0};

    while( (a = getchar())!='\n')
        str[a - '0']++;

    for (int i = 9; i >=0;i--)
        for (int j = 0; j < str[i];j++)
            putchar(i+'0');

    return 0;
}