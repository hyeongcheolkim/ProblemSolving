#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;

constexpr int SIZE = 5;
vector<pos> position;
vector<vector<int>> vst;
vector<vector<reference_wrapper<int>>> verticals, horizontals, diagonals(2);

bool check(int num = 3)
{
    int cnt = 0;
    for (auto& type : {verticals, horizontals, diagonals})
        for (auto& e : type)
            if (all_of(e.begin(), e.end(), [](auto& e) {return e; }))
                ++cnt;
    if (cnt >= 3)
        return true;
    else
        return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    position.resize(SIZE * SIZE + 1);
    vst.resize(SIZE + 1, vector<int>(SIZE + 1));
    for (int i = 1; i <= SIZE; ++i)
        for (int j = 1; j <= SIZE; ++j)
        {
            int num;
            cin >> num;
            position[num] = {i, j};
        }
    for (int i = 1; i <= SIZE; ++i)
    {
        vector<reference_wrapper<int>> vertical, horizontal;
        for (int j = 1; j <= SIZE; ++j)
        {
            vertical.emplace_back(vst[i][j]);
            horizontal.emplace_back(vst[j][i]);
        }
        verticals.push_back(vertical);
        horizontals.push_back(horizontal);
    }
    for (int i = 1; i <= SIZE; ++i)
    {
        diagonals[0].emplace_back(vst[i][i]);
        diagonals[1].emplace_back(vst[i][SIZE + 1 - i]);
    }
    for (int i = 1; i <= SIZE * SIZE; ++i)
    {
        int num;
        cin >> num;
        const auto& [r, c] = position[num];
        vst[r][c] = true;
        if (check())
        {
            cout << i;
            break;
        }
    }
    return 0;
}