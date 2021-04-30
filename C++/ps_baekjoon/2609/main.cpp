//baekjoon ps 2609

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, temp1, temp2, maxi;
    int res1 = 1;
    int res2 = 1;
    cin >> n >> m;
    maxi = max(n, m);
    vector<int> arr1(maxi+1, 0);
    vector<int> arr2(maxi+1, 0);
    temp1 = n;
    temp2 = m;
    for (int i = 2; i <= n; i++)
    {
        if (temp1 == 1)
            break;
        while (temp1 % i == 0)
        {
            arr1[i]++;
            temp1 /= i;
        }
    }
    for (int i = 2; i <= m; i++)
    {
        if (temp2 == 1)
            break;
        while (temp2 % i == 0)
        {
            arr2[i]++;
            temp2 /= i;
        }
    }
    for (int i = 2; i <= maxi; i++)
    {
        if (arr1[i] != 0 && arr2[i] != 0)
            res1 *= pow(i,min(arr1[i], arr2[i]));
        if(arr1[i]!=0 || arr2[i]!=0)
            res2 *= pow(i,max(arr1[i], arr2[i]));
    }
    cout << res1 << '\n';
    cout << res2 << '\n';
    return 0;
}