//baekjoon ps 11725

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> data(n + 1);
    vector<int> parent(n + 1);
    queue<int> q;
    for (int i = 0; i < n - 1;i++)
    {
        static int n1, n2;
        cin >> n1 >> n2;
        data[n1].push_back(n2);
        data[n2].push_back(n1);
    }
    q.push(1);
    parent[1] = 1;
    while (!q.empty())
    {
        int num = q.front();
        q.pop();
        for (int i = 0; i < data[num].size(); i++)
            if (!parent[data[num][i]])
            {
                q.push(data[num][i]);
                parent[data[num][i]] = num;
            }
    }
    for (int i = 2; i <= n; i++)
        cout << parent[i] << '\n';
    return 0;
}