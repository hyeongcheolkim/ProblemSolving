//baekjoon 11650 ps

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
        scanf("%d%d",&arr[i].first, &arr[i].second) ;

    sort(&arr[0], &arr[n]);

    for (int i = 0; i < n; i++)
        printf("%d %d\n",arr[i].first, arr[i].second);

    delete[] arr;
    return 0;
}