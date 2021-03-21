//baekjoon 2775 ps

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int member(int k, int n);

int main()
{
    int repeat = 0;
    scanf("%d", &repeat);
    int *answer = (int *)malloc(sizeof(int) * repeat);
    for (int i = 0; i < repeat; i++)
    {
        int k, n;
        scanf("%d%d", &k, &n);
        answer[i] = member(k, n);
    }
    for (int i = 0; i < repeat; i++)
    {
        if (i < repeat - 1)
            printf("%d\n", answer[i]);
        else
            printf("%d", answer[i]);
    }

    return 0;
}

int member(const int k, const int n)
{
    //2dimensional matrix row:k column:n  k X n
    int **arr = (int **)malloc(sizeof(int *) * (k + 1));
    for (int i = 0; i < k + 1; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * n);
        memset(arr[i], 0, sizeof(int) * n);
    }

    for (int i = 0; i < n; i++)
        arr[0][i] = i + 1;
    for (int j = 1; j < k + 1; j++)
        for (int i = 0; i < n; i++)
            for (int x = 0; x <= i; x++)
                arr[j][i] += arr[j - 1][x];
    return arr[k][n - 1];
}