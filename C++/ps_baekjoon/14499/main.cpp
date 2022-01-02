#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 20;
int n, m, x, y, k, board[mxN][mxN];

class Dice
{
private:
    int row, col;
    int top, bottom, up, down, left, right;
public:
    Dice(const int& row, const int& col)
    {
        this->row = row;
        this->col = col;
        top = bottom = up = down = left = right = 0;
    }
    bool move_up()
    {
        if (row - 1 < 0)
            return false;
        --row;
        int temp = top;
        top = down;
        down = bottom;
        bottom = up;
        up = temp;
        return true;
    }
    bool move_down()
    {
        if (row + 1 >= n)
            return false;
        ++row;
        int temp = top;
        top = up;
        up = bottom;
        bottom = down;
        down = temp;
        return true;
    }
    bool move_left()
    {
        if (col - 1 < 0)
            return false;
        --col;
        int temp = top;
        top = right;
        right = bottom;
        bottom = left;
        left = temp;
        return true;
    }
    bool move_right()
    {
        if (col + 1 >= m)
            return false;
        ++col;
        int temp = top;
        top = left;
        left = bottom;
        bottom = right;
        right = temp;
        return true;
    }
    void set_bot(const int& num) { bottom = num; }
    int get_top() { return top; }
    int get_bot() { return bottom; }
    int get_row() { return row; }
    int get_col() { return col; }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> board[i][j];
    Dice dice(x, y);
    while (k--)
    {
        int oper;
        bool flag = false;
        cin >> oper;
        switch (oper)
        {
        case 1: flag = dice.move_right(); break;
        case 2: flag = dice.move_left(); break;
        case 3: flag = dice.move_up(); break;
        case 4: flag = dice.move_down(); break;
        default: flag = false; break;
        }
        if (flag)
        {
            cout << dice.get_top() << '\n';
            int row = dice.get_row();
            int col = dice.get_col();
            if (int& num = board[row][col]; num == 0)
                num = dice.get_bot();
            else
            {
                dice.set_bot(num);
                num = 0;
            }
        }
    }
    return 0;
}