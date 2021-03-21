// cpp algorithm ps number 13

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int arr[10] = {0};
    char a;
    int max = -1;
    int index = 0;
    while((a=getchar())!='\n')
        arr[a - '0']++;
    
    for(int i=0;i<10;i++)
        if(arr[i]>=max)
        {
            max = arr[i];
            index = i;
        }

    printf("%d", index);
}