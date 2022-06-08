#include <bits/stdc++.h>
using namespace std;

constexpr int WHITE_PAPER_SIZE = 100, BLACK_PAPER_SIZE = 10;
constexpr int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
int n;
vector<vector<int>> white_paper;



void put_black_paper(const int& row, const int& col)
{
    for (int i = row; i < row + BLACK_PAPER_SIZE; ++i)
        for (int j = col; j < col + BLACK_PAPER_SIZE; ++j)
        {
            if (!(1 <= i && i <= WHITE_PAPER_SIZE && 1 <= j && j <= WHITE_PAPER_SIZE))
                continue;
            white_paper[i][j] = 1;
        }
}

int calculate_perimeter()
{
    int ret = 0;
    for (int i = 1; i <= WHITE_PAPER_SIZE; ++i)
        for (int j = 1; j <= WHITE_PAPER_SIZE; ++j)
            if (white_paper[i][j] == 1)
            {
                for (int direction = 0; direction < 4; ++direction)
                {
                    int nr = i + dr[direction];
                    int nc = j + dc[direction];
                    if (white_paper[nr][nc] == 0)
                        ++ret;
                }
            }
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    white_paper.resize(WHITE_PAPER_SIZE + 1, vector<int>(WHITE_PAPER_SIZE + 1));
    while (n--)
    {
        int row, col;
        cin >> row >> col;
        put_black_paper(row, col);
    }
    cout << calculate_perimeter();

    return 0;
}