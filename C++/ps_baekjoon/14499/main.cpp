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
    Dice(const int& row, const int& col) {
        this->row = row;
        this->col = col;
        this->top = 0;
        this->bottom = 0;
        this->up = 0;
        this->down = 0;
        this->left = 0;
        this->right = 0;
    }
    bool move_up()
    {
        if (row - 1 < 0)
            return false;
        --row;
        int temp = this->top;
        this->top = this->down;
        this->down = this->bottom;
        this->bottom = this->up;
        this->up = temp;
        return true;
    }
    bool move_down()
    {
        if (row + 1 >= n)
            return false;
        ++row;
        int temp = this->top;
        this->top = this->up;
        this->up = this->bottom;
        this->bottom = this->down;
        this->down = temp;
        return true;
    }
    bool move_left()
    {
        if (col - 1 < 0)
            return false;
        --col;
        int temp = this->top;
        this->top = this->right;
        this->right = this->bottom;
        this->bottom = this->left;
        this->left = temp;
        return true;
    }
    bool move_right()
    {
        if (col + 1 >= m)
            return false;
        ++col;
        int temp = this->top;
        this->top = this->left;
        this->left = this->bottom;
        this->bottom = this->right;
        this->right = temp;
        return true;
    }
    int get_top() { return this->top; }
    int get_bot() { return this->bottom; }
    void set_bot(const int& num) { this->bottom = num; }
    int get_row() { return this->row; }
    int get_col() { return this->col; }
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
        case 1:
            flag = dice.move_right();
            break;
        case 2:
            flag = dice.move_left();
            break;
        case 3:
            flag = dice.move_up();
            break;
        case 4:
            flag = dice.move_down();
            break;
        default:
            flag = false;
            break;
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