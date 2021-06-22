//baekjoon ps 15654

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr;
vector<bool> check;

void dfs(int level)
{
    static vector<int> res;
    if (level == m)
    {
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
        if (!check[i])
        {
            check[i] = true;
            res.push_back(arr[i]);
            dfs(level + 1);
            res.pop_back();
            check[i] = false;
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    arr = vector<int>(n);
    check = vector<bool>(n, false);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    dfs(0);
    return 0;
}