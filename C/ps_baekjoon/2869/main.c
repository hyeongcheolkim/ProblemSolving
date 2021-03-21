//baekjoon 2869 ps

#include <stdio.h>
#include <math.h>

int main()
{

    unsigned int a, b, v;
    scanf("%u%u%u", &a, &b, &v);

    printf("%d", (int)ceil((double)(v - a) / (double)(a - b)) + 1);
    return 0;
}
