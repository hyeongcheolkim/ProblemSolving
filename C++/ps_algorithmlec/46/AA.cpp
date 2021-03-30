// cpp algorithm ps number 46

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k, p = 0, cnt = 0, tot = 0;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        tot += arr[i];
    }
    cin >> k;

    if (k >= tot)
    {
        cout << -1;
        return 0;
    }
    while(1)
    {
        p++;
        if(p>n)
            p = 1;
        if(arr[p]==0)
            continue;
        arr[p]--;
        cnt++;
        if(cnt==k)
            break;
    }
    while(1)
    {
        p++;
        if(p>n)
            p = 1;
        if(arr[p]!=0)
            break;
    }
    cout << p;
    return 0;
}