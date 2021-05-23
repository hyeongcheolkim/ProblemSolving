//baekjoon ps 16928

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(10 + 2, vector<int>(10 + 2));
    vector<int> check(100 + 1, numeric_limits<int>::max());
    queue<pair<unsigned short, unsigned short>> q;
    unordered_map<int, int> ladder;
    unordered_map<int, int> snake;
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
            map[i][j] = (i - 1) * 10 + j;
    while (n--)
    {
        int to, go;
        cin >> to >> go;
        ladder[to] = go;
    }
    while (m--)
    {
        int to, go;
        cin >> to >> go;
        snake[to] = go;
    }
    q.push({1, 0});
    while (!q.empty())
    {
        if (q.front().first == 100)
            break;
        int num = q.front().first;
        int cnt = q.front().second;
        check[num] = cnt;
        q.pop();
        for (int i = 1; i <= 6; i++)
            if (num + i <= 100 && check[num + i] > cnt + 1)
            {
                if (ladder.find(num + i) != ladder.end())
                    q.push({ladder[num + i], cnt + 1});
                else if (snake.find(num + i) != snake.end())
                    q.push({snake[num + i], cnt + 1});
                else
                    q.push({num + i, cnt + 1});
            }
    }
    cout << q.front().second;
    return 0;
}