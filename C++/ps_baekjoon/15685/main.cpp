#include <bits/stdc++.h>
using namespace std;

constexpr int SIZE = 100;
vector<vector<bool>> board(SIZE + 1, vector<bool>(SIZE + 1));
int n, cnt;

class Vec
{
private:
    int direction;
public:
    Vec() {}
    Vec(const int& direction) { this->direction = direction; }
    void rotate()
    {
        if (++direction >= 4)
            direction = 0;
    }
    pair<int, int> get_diff()
    {
        static const vector<pair<int, int>> diff{
            {0, +1},
            {-1, 0},
            {0, -1},
            {+1, 0},
        };
        return diff[direction];
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    while (n--)
    {
        int r, c, d, g;
        cin >> c >> r >> d >> g;
        vector<Vec> vecs{Vec{d}};
        board[r][c] = true;
        while (g--)
        {
            auto tmp = vecs;
            for_each(tmp.begin(), tmp.end(), [](Vec& e) {e.rotate(); });
            vecs.insert(vecs.end(), tmp.rbegin(), tmp.rend());
        }
        for (auto& e : vecs)
        {
            auto [dr, dc] = e.get_diff();
            r += dr;
            c += dc;
            board[r][c] = true;
        }
    }
    for (int i = 0; i < 100; ++i)
        for (int j = 0; j < 100; ++j)
        {
            bool b1 = board[i][j];
            bool b2 = board[i + 1][j];
            bool b3 = board[i][j + 1];
            bool b4 = board[i + 1][j + 1];
            if (b1 & b2 & b3 & b4)
                ++cnt;
        }
    cout << cnt;
    return 0;
}