//baekjoon ps 15652

#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;

void bfs(int level, int num)
{
    if (level == m)
    {
        for (const auto &e : arr)
            cout << e << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1 + num; i <= n; i++)
    {
        arr.push_back(i);
        bfs(level + 1, num);
        arr.pop_back();
        num++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    bfs(0, 0);
    return 0;
}