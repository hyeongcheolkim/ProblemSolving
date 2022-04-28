#include <bits/stdc++.h>
using namespace std;

int n, s, p;
vector<int> arr1, arr2;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s >> p;
    arr1.reserve(n);
    arr2.reserve(n);
    while (n--)
    {
        int num;
        cin >> num;
        if (num >= s)
            arr1.push_back(num);
        if (num > s)
            arr2.push_back(num);
    }
    if (arr1.size() < p)
        cout << arr2.size() + 1;
    else
        cout << -1;
    return 0;
}