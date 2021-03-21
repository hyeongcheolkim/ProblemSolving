//baekjoon 1011 ps

#include <stdio.h>

int main()
{
    int n = 0;
    int x;

    scanf("%d", &x);

    for (n = 0; (n) * (n + 1) / 2 < x; n++)
        continue;

    x -= (n) * (n - 1) / 2;

    if (n % 2 == 0)
        printf("%d/%d", x, n + 1 - x);
    else if (n % 2 == 1)
        printf("%d/%d", n + 1 - x, x);

    return 0;
}
