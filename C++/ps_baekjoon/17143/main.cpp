#include <bits/stdc++.h>
using namespace std;

struct Shark
{
    int r, c, s, d, z;
    bool live = true;
    Shark() {}
    Shark(int& r, int& c, int& s, int& d, int& z)
    {
        this->r = r;
        this->c = c;
        this->s = s;
        this->d = d;
        this->z = z;
    }
};

constexpr int mxRC = 100;
int row, col, m, res, vst[mxRC + 1][mxRC + 1];;
vector<Shark> sharks;
map<int, pair<int, int>> direction{
    {1, {-1, 0}},
    {2, {+1, 0}},
    {3, {0, +1}},
    {4, {0, -1}},
};
map<int, int> change_direction{
    {1, 2},
    {2, 1},
    {3, 4},
    {4, 3},
};

void shark_move()
{
    memset(vst, false, sizeof(vst));
    for (int idx = 1; idx <= m; ++idx)
    {
        if (!sharks[idx].live)
            continue;
        auto& [r, c, s, d, z, live] = sharks[idx];
        auto [dr, dc] = direction[d];
        for (int i = 0; i < s; ++i)
        {
            r += dr;
            c += dc;
            if (!(1 <= r && r <= row && 1 <= c && c <= col))
            {
                d = change_direction[d];
                dr = direction[d].first;
                dc = direction[d].second;
                r += dr * 2;
                c += dc * 2;
            }
        }
        if (vst[r][c])
        {
            if (sharks[vst[r][c]].z > z)
            {
                sharks[idx].live = false;
                continue;
            }
            sharks[vst[r][c]].live = false;
            vst[r][c] = idx;
        }
        else
            vst[r][c] = idx;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> row >> col >> m;
    sharks.resize(m + 1);
    for (int idx = 1; idx <= m; ++idx)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        if (d == 1 || d == 2)
            s %= (row - 1) * 2;
        else if (d == 3 || d == 4)
            s %= (col - 1) * 2;
        sharks[idx] = Shark(r, c, s, d, z);
        vst[r][c] = idx;
    }
    for (int king = 1; king <= col; ++king)
    {
        for (int r = 1; r <= row; ++r)
            if (vst[r][king])
            {
                res += sharks[vst[r][king]].z;
                sharks[vst[r][king]].live = false;
                break;
            }
        shark_move();
    }
    cout << res;
    return 0;
}