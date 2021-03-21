//baekjoon 10757 ps

#include <stdio.h>
#include <string.h>
#include <memory.h>

#define MAXSIZE 10005

int main()
{
    //배열 2개를 정의, sprintf용 배열 2개 추가.
    char str_input1[MAXSIZE];
    char str_input2[MAXSIZE];
    char str1[MAXSIZE];
    char str2[MAXSIZE];
    char result[MAXSIZE]="";
    memset(result, '0', sizeof(char) * (MAXSIZE));

    //배열 2개를 받고 sprintf를 통해 빈공간에 0채우기
    scanf("%s%s", str_input1, str_input2);

    sprintf(str1, "%010004s", str_input1);
    sprintf(str2, "%010004s", str_input2);
    for (int i = 0; i < strlen(str1);i++)
        if(str1[i]==32)
            str1[i] = '0';
    for (int i = 0; i < strlen(str1);i++)
        if(str2[i]==32)
            str2[i] = '0';
        printf("%d", str1[5]);

    //계산부분
    for (int i = strlen(str1) - 1; i >= 0; i--)
    {
        result[i] += (str1[i] + str2[i] + result[i + 1] - 3 * '0') / 10;
        result[i + 1] = (str1[i] + str2[i] + result[i + 1] - 3 * '0') % 10 + '0';

    }

    //index를 이용해 처음으로 0이아닌 숫자의 위치를 기억
    //index부터 값 출력

    int index = 0;
    for (; result[index] == '0'; index++)
        continue;


    for(;index<MAXSIZE;index++)
        printf("%c", result[index]);

    return 0;
}