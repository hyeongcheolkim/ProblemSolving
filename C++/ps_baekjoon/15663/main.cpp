//baekjoon ps 15663

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr;

void dfs(int level)
{
    static vector<int> temp;
    static vector<bool> check(n, false);
    int prev = -1;
    if (level == m)
    {
        for (int i = 0; i < temp.size(); i++)
            cout << temp[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < arr.size(); i++)
        if (!check[i] && prev != arr[i])
        {
            check[i] = true;
            temp.push_back(arr[i]);
            prev = arr[i];
            dfs(level + 1);
            check[i] = false;
            temp.pop_back();
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    arr = vector<int>(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    dfs(0);
    return 0;
}