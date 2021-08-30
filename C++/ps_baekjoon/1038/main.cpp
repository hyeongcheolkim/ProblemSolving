#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max();
int n, cnt = -1;
vector<int> arr;

void dfs(int digit)
{
    if (arr.size() - 1 == digit)
    {
        ++cnt;
        if (cnt == n)
        {
            for (int i = 1; i < arr.size(); ++i)
                cout << arr[i];
            exit(0);
        }
        return;
    }
    for (int num = 0; num <= 9; ++num)
        if (arr.back() > num)
        {
            arr.push_back(num);
            dfs(digit);
            arr.pop_back();
        }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    arr.reserve(10);
    arr.push_back(INF);
    for (int digit = 1; digit <= 10; ++digit)
        dfs(digit);
    cout << -1;
    return 0;
}