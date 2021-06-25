//baekjoon ps 15657

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr;

void dfs(int level, int index)
{
    static vector<int> temp;
    if (level == m)
    {
        for (int i = 0; i < temp.size(); i++)
            cout << temp[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = index; i < arr.size(); i++)
    {
        temp.push_back(arr[i]);
        dfs(level + 1, i);
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
    dfs(0, 0);
    return 0;
}