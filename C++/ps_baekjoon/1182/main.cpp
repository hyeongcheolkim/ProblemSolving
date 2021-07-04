//baekjoon ps 1182

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, s;
    int res = 0;
    cin >> n >> s;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    function<void(int, int, int)> dfs = [&](const int &size, int index, int cnt)
    {
        static vector<int> temp;
        if (size == cnt)
        {
            int sum = 0;
            for (int i = 0; i < temp.size(); i++)
                sum += temp[i];
            if (sum == s)
                res++;
            return;
        }
        for (int i = index; i < n; i++)
        {
            temp.push_back(arr[i]);
            dfs(size, i + 1, cnt + 1);
            temp.pop_back();
        }
    };
    for (int i = 1; i <= n; i++)
        dfs(i, 0, 0);
    cout << res;
    return 0;
}