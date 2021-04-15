// cpp algorithm ps number 87

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct pos
{
    int row, column;
    pos(const int &row, const int &column)
    {
        this->row = row;
        this->column = column;
    }
    pos left()
    {
        return pos(this->row, this->column - 1);
    }
    pos right()
    {
        return pos(this->row, this->column + 1);
    }
    pos up()
    {
        return pos(this->row - 1, this->column);
    }
    pos down()
    {
        return pos(this->row + 1, this->column);
    }
    pos leftup()
    {
        return pos(this->row - 1, this->column - 1);
    }
    pos leftdown()
    {
        return pos(this->row + 1, this->column - 1);
    }
    pos rightup()
    {
        return pos(this->row - 1, this->column + 1);
    }
    pos rightdown()
    {
        return pos(this->row + 1, this->column + 1);
    }
    bool invalid(const int &n)
    {
        if (0 <= this->row && this->row < n && 0 <= this->column && this->column < n)
            return true;
        else
            return false;
    }
} pos;

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    vector<vector<int>> map(n, vector<int>(n));
    vector<vector<bool>> check(n, vector<bool>(n, true));
    queue<pos> Q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 1 && check[i][j])
            {
                Q.push(pos(i, j));
                while (!Q.empty())
                {
                    pos left = Q.front().left();
                    pos right = Q.front().right();
                    pos up = Q.front().up();
                    pos down = Q.front().down();
                    pos leftup = Q.front().leftup();
                    pos leftdown = Q.front().leftdown();
                    pos rightup = Q.front().rightup();
                    pos rightdown = Q.front().rightdown();
                    check[Q.front().row][Q.front().column] = false;

                    Q.pop();

                    if (left.invalid(n))
                    {
                        if (check[left.row][left.column] && map[left.row][left.column] == 1)
                            Q.push(left);
                        check[left.row][left.column] = false;
                    }
                    if (right.invalid(n))
                    {
                        if (check[right.row][right.column] && map[right.row][right.column] == 1)
                            Q.push(right);
                        check[right.row][right.column] = false;
                    }
                    if (up.invalid(n))
                    {
                        if (check[up.row][up.column] && map[up.row][up.column] == 1)
                            Q.push(up);
                        check[up.row][up.column] = false;
                    }
                    if (down.invalid(n))
                    {
                        if (check[down.row][down.column] && map[down.row][down.column] == 1)
                            Q.push(down);
                        check[down.row][down.column] = false;
                    }
                    if (leftup.invalid(n))
                    {
                        if (check[leftup.row][leftup.column] && map[leftup.row][leftup.column] == 1)
                            Q.push(leftup);
                        check[leftup.row][leftup.column] = false;
                    }
                    if (leftdown.invalid(n))
                    {
                        if (check[leftdown.row][leftdown.column] && map[leftdown.row][leftdown.column] == 1)
                            Q.push(leftdown);
                        check[leftdown.row][leftdown.column] = false;
                    }
                    if (rightup.invalid(n))
                    {
                        if (check[rightup.row][rightup.column] && map[rightup.row][rightup.column] == 1)
                            Q.push(rightup);
                        check[rightup.row][rightup.column] = false;
                    }
                    if (rightdown.invalid(n))
                    {
                        if (check[rightdown.row][rightdown.column] && map[rightdown.row][rightdown.column] == 1)
                            Q.push(rightdown);
                        check[rightdown.row][rightdown.column] = false;
                    }
                }
                cnt++;
            }
        }
    cout << cnt;
    return 0;
}