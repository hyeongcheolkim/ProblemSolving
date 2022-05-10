#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_LINE = 6;
int n, p, cnt;
vector<priority_queue<int>> board;
vector<vector<bool>> vst;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> p;
    vst.resize(MAX_LINE + 1, vector<bool>(p + 1));
    board.resize(MAX_LINE + 1);
    while (n--)
    {
        int line, fret;
        cin >> line >> fret;
        auto& now_pq = board[line];
        if (!vst[line][fret])
        {
            ++cnt;
            vst[line][fret] = true;
            now_pq.push(fret);
        }
        while (now_pq.top() != fret)
        {
            vst[line][now_pq.top()] = false;
            now_pq.pop();
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}