//baekjoon 10250 ps

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int roomnumber(int h, int w, int n);

int main()
{
    int repeat_num;
    scanf("%d", &repeat_num);
    int *roomarr = (int *)malloc(sizeof(int) * repeat_num);

    for (int i = 0; i < repeat_num; i++)
    {
        int h, w, n;
        scanf("%d%d%d", &h, &w, &n);
        roomarr[i] = roomnumber(h, w, n);
    }

    for (int i = 0; i < repeat_num; i++)
    {
        if (i < repeat_num - 1)
            printf("%d\n", roomarr[i]);
        else
            printf("%d", roomarr[i]);
    }

    free(roomarr);
    return 0;
}

int roomnumber(int h, int w, int n)
{

    int floor;
    if (n % h != 0)
        floor = n % h;
    else if (n % h == 0)
        floor = h;

    int roomnumber = (int)ceil((double)n / (double)h);

    return 100 * floor + roomnumber;
}