//baekjoon 1193 ps

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//오버플로우 방지 unsigned long long
unsigned long long number_min(unsigned long long x, unsigned long long y);

int main()
{

    int repeat_num;
    unsigned long long x, y;
    scanf("%d", &repeat_num);

    unsigned long long *answer = (unsigned long long *)malloc(sizeof(unsigned long long) * repeat_num);
    for (int i = 0; i < repeat_num;i++)
    {
        scanf("%llu%llu", &x, &y);
        answer[i]=number_min(x, y);
    }

    for (int i = 0; i < repeat_num;i++)
        printf("%llu\n", answer[i]);

        return 0;
}

unsigned long long number_min(unsigned long long x, unsigned long long y)
{
    unsigned long long distance = y - x;
    unsigned long long n;
    
    n=(int)ceil((sqrt(1.0+4*distance)-1)/2.0);
    

    return (distance <= n * n) ? (2 * n - 1) : (2 * n);
}
