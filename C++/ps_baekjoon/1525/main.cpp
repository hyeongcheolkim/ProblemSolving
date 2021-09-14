#include <bits/stdc++.h>
using namespace std;

constexpr int SOLVED = 123456789, SIZE = 3, dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
int puzzle[SIZE][SIZE];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    string str;
    str.reserve(9);
    for (int i = 0; i < 9; ++i)
    {
        int num;
        cin >> num;
        if (num == 0)
            num = 9;
        str.push_back('0' + num);
    }
    int init = stoi(str);
    queue<int> q;
    unordered_map<int, int> vst;
    q.push(init);
    vst[init] = 0;
    while (!q.empty())
    {
        int now_int = q.front();
        string now_str = to_string(now_int);
        q.pop();
        if (now_int == SOLVED)
            break;
        int pos = now_str.find('9');
        int r = pos / 3;
        int c = pos % 3;
        for (int direction = 0; direction < 4; ++direction)
        {
            int nr = r + dr[direction];
            int nc = c + dc[direction];
            if (!(0 <= nr && nr < 3 && 0 <= nc && nc < 3))
                continue;
            string temp = now_str;
            swap(temp[pos], temp[nr * 3 + nc]);
            int next = stoi(temp);
            if (!vst[next])
            {
                vst[next] = vst[now_int] + 1;
                q.push(next);
            }
        }
    }
    cout << (vst.find(SOLVED) == vst.end() ? -1 : vst[SOLVED]);
    return 0;
}