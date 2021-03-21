//baekjoon 1181 ps

#include <stdio.h>

int main()
{
    char *s1 = "hello";
    char *s2="";
    scanf("%s", &s2);

    printf("%s", s1);

    printf("%s", &s2);
    printf("%c", s2);

    return 0;
}