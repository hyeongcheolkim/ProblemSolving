//baekjoon 10989 ps

#include <stdio.h>
#define SIZE 10000 + 1

int main()
{
    unsigned int n;
    scanf("%ud", &n);

    unsigned int arr[SIZE] = {0};

    //counting sort(num<=10'000)
    for (int i = 0; i < n; i++)
    {
        static int num = 0;
        scanf("%d", &num);
        arr[num]++;
    }

    for (int i = 1; i <= 10000; i++)
        if (arr[i] != 0)
            for (int j = 0; j < arr[i]; j++)
                printf("%d\n", i);

    return 0;
}