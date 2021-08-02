//baekjoon ps 9466

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int cnt = 0;
        int n;
        cin >> n;
        vector<int> arr(n + 1);
        vector<bool> check(n + 1), visited(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        static function<void(int)> dfs = [&](int now_num)
        {
            int next_num = arr[now_num];
            visited[now_num] = true;
            if (!visited[next_num])
                dfs(next_num);
            else if (!check[next_num])
            {
                for (int i = next_num; i != now_num; i = arr[i])
                    cnt++;
                cnt++;
            }
            check[now_num] = true;
        };
        for (int i = 1; i <= n; i++)
            if (!visited[i])
                dfs(i);
        cout << n - cnt << '\n';
    }
    return 0;
}