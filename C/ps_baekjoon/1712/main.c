//baekjoon 1712 ps

#include <stdio.h>

int main()
{
    unsigned int a, b, c;

    scanf("%d%d%d", &a, &b, &c);

    if (c > b)
    {
        int num=0;
        num = (int)(a / (c - b)) + 1;
        printf("%d", num);
    }
    else
        printf("-1");

    return 0;
}