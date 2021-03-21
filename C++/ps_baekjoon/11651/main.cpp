//baekjoon 11651 ps

#include <stdio.h>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    typedef pair<int,int> pos;

    int n;
    scanf("%d",&n);
    pos *arr = new pos[n];

    for (int i = 0; i < n; i++)
        scanf("%d%d",&arr[i].second, &arr[i].first) ;

    sort(&arr[0], &arr[n]);

    for (int i = 0; i < n; i++)
        printf("%d %d\n",arr[i].second, arr[i].first);

    delete[] arr;
    return 0;
}