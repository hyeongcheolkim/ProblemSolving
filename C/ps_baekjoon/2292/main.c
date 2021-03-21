//baekjoon 2292 ps

#include <stdio.h>

int main()
{
    unsigned int n;
    scanf("%d", &n);

    int orbi = 1;
    while(1)
    {
        if(3*orbi*orbi-3*orbi+1<n)
            orbi++;
        else
            break;
    }
    printf("%d", orbi);
}