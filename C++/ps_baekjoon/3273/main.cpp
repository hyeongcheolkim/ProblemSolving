//baekjoon ps 3273

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, x, res = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> x;
    sort(arr.begin(), arr.end());
    int lt = 0;
    int rt = n - 1;
    while (lt < rt)
    {
        if (arr[lt] + arr[rt] == x)
        {
            res++;
            lt++;
            rt--;
        }
        if (arr[lt] + arr[rt] < x)
            lt++;
        if (arr[lt] + arr[rt] > x)
            rt--;
    }
    cout << res;
    return 0;
}