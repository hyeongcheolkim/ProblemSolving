#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;

constexpr int BOARD_SIZE = 8;
pos king, stone;
int n;
map<string, pair<int, int>> diff{
    {"R", {0, +1}},
    {"L", {0, -1}},
    {"B", {+1, 0}},
    {"T", {-1, 0}},
    {"RT", {-1, +1}},
    {"LT", {-1, -1}},
    {"RB", {+1, +1}},
    {"LB", {+1, -1}},
};

pos get_pos(string str)
{
    int row = BOARD_SIZE - (str[1] - '0') + 1;
    int col = str[0] - 'A' + 1;
    return pos{row, col};
}

string get_chess_pos(pos p)
{
    string ret;
    auto [row, col] = p;
    ret.push_back('A' + col - 1);
    ret.push_back('0' + BOARD_SIZE - (row - 1));
    return ret;
}

bool is_out_of_bound(int row, int col)
{
    return !(1 <= row && row <= BOARD_SIZE && 1 <= col && col <= BOARD_SIZE);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    string k, s;
    cin >> k >> s;
    king = get_pos(k);
    stone = get_pos(s);
    cin >> n;
    while (n--)
    {
        string oper;
        cin >> oper;
        auto [dr, dc] = diff[oper];
        auto [kr, kc] = king;
        int knr = kr + dr;
        int knc = kc + dc;
        if (is_out_of_bound(knr, knc))
            continue;
        if (pos{knr, knc} == stone)
        {
            auto [sr, sc] = stone;
            int snr = sr + dr;
            int snc = sc + dc;
            if (is_out_of_bound(snr, snc))
                continue;
            stone = {snr, snc};
        }
        king = {knr, knc};
    }
    cout << get_chess_pos(king) << '\n';
    cout << get_chess_pos(stone);
    return 0;
}