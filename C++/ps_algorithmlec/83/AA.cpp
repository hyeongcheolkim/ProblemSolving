// cpp algorithm ps number 83

#include <iostream>
#include <stdio.h>
using namespace std;

int arr[10];
bool check[10];

int send()
{
    return arr[6] * 1000 + arr[1] * 100 + arr[3] * 10 + arr[0];
}
int more()
{
    return arr[2] * 1000 + arr[4] * 100 + arr[5] * 10 + arr[1];
}
int money()
{
    return arr[2] * 10000 + arr[4] * 1000 + arr[3] * 100 + arr[1] * 10 + arr[7];
}

void dfs(int n)
{
    if (n == 8)
    {
        if (send() + more() == money())
        {
            if(arr[2]==0||arr[6]==0)
                return;
            printf("  %d %d %d %d\n", arr[6], arr[1], arr[3], arr[0]);
            printf("  %d %d %d %d\n", arr[2], arr[4], arr[5], arr[1]);
            printf("-----------\n");
            printf("%d %d %d %d %d\n", arr[2], arr[4], arr[3], arr[1], arr[7]);
        }
        return;
    }
        
    for (int i = 0; i < 10; i++)
    {
        if (!check[n])
        {
            arr[n] = i;
            check[n] = true;
            dfs(n + 1);
            check[n] = false;
        }
    }
}

int main()
{
    dfs(0);
    return 0;
}