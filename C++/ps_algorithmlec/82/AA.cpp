// cpp algorithm ps number 82

#include <iostream>
#include <vector>

using namespace std;

int n, r;

void dfs(int level, vector<int> &arr)
{
    static int cnt = 0;
    static vector<int> temp;
    static vector<bool> trace(n, true);

    if (temp.size() == r)
    {
        for (const auto &e : temp)
            cout << e << ' ';
        cout << '\n';
            return;
    }

    for (int i = 0; i < n; i++)
    {
        if (trace[i])
        {
            temp.push_back(arr[i]);
            trace[i] = false;
            dfs(level + 1, arr);
            temp.pop_back();
            trace[i] = true;
        }
    }
}

int main()
{
    cin >> n >> r;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    dfs(0, arr);
    return 0;
}