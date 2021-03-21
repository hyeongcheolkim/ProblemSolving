//baekjoon 1316 ps

#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
#define MAXSIZE 100
#define num_alphabet 26
int isgroupnum(int *arr, int size);

int main()
{
    int n;
    int counter = 0;
    char str[MAXSIZE];
    memset(str, 0, sizeof(char) * MAXSIZE);

    scanf("%d", &n);

    for (int x = 0; x < n; x++)
    {
        int flag = 1;
        scanf("%s", str);

        int *cmpstr = malloc(sizeof(int) * strlen(str));
        memset(cmpstr, 0, sizeof(int) * strlen(str));

        for (char i = 'a'; i < 'a' + num_alphabet; i++)
        {
            memset(cmpstr, 0, sizeof(int) * strlen(str));

            for (int j = 0; j < strlen(str); j++)
            {
                if (str[j] == i)
                    cmpstr[j]++;
            }
            if (!isgroupnum(cmpstr, strlen(str)))
                flag = 0;
        }
        if (flag)
            counter++;
        free(cmpstr);
    }

    printf("%d", counter);

    return 0;
}

int isgroupnum(int *arr, int size)
{
    int index = -1;
    int flag = 1;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 1)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
        return flag;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 1)
        {
            if (i == index)
                continue;
            else if (i == index + 1)
                index++;
            else
                flag = 0;
        }
    }
    return flag;
}