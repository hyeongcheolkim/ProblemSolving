//baekjoon 2839 ps

#include <stdio.h>
#include <math.h>
#include <memory.h>

int main()
{
    int N;
    int five_num = 0;
    int three_num = -1;

    scanf("%d", &N);

    five_num = (int)floor((double)N / 5.0);

    for (five_num; five_num >= 0; five_num--)
    {
        int total = N;
        total -= (five_num * 5);
        if (total % 3 == 0)
        {
            three_num = total / 3;
            break;
        }
    }
    if(three_num==-1)
        printf("%d", -1);
    else
        printf("%d", five_num + three_num);

    return 0;
}
