// cpp algorithm ps number 89

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
    bool invalid(const int &row, const int &column)
    {
        if (0 <= this->row && this->row < row && 0 <= this->column && this->column < column)
            return true;
        else
            return false;
    }
} pos;

int main()
{
    int n, m;
    int cnt = 0;
    int day = 0;
    cin >> m >> n;
    int tomato = n * m;

    vector<vector<int>> box(n, vector<int>(m));
    vector<vector<bool>> check(n, vector<bool>(m, false));
    vector<vector<int>> timecost(n, vector<int>(m, 0));
    queue<pos> Q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> box[i][j];
            switch (box[i][j])
            {
            case 1:
                check[i][j] = true;
                Q.push(pos(i, j));
                break;
            case -1:
                check[i][j] = true;
                tomato--;
                break;
            default:
                break;
            }
        }
    while (!Q.empty())
    {
        pos temp = Q.front();
        Q.pop();
        cnt++;
        pos left = temp.left();
        pos right = temp.right();
        pos up = temp.up();
        pos down = temp.down();
        if (left.invalid(n, m) && !check[left.row][left.column])
        {
            Q.push(left);
            check[left.row][left.column] = true;
            timecost[left.row][left.column] = timecost[temp.row][temp.column] + 1;
        }
        if (right.invalid(n, m) && !check[right.row][right.column])
        {
            Q.push(right);
            check[right.row][right.column] = true;
            timecost[right.row][right.column] = timecost[temp.row][temp.column] + 1;
        }
        if (down.invalid(n, m) && !check[down.row][down.column])
        {
            Q.push(down);
            check[down.row][down.column] = true;
            timecost[down.row][down.column] = timecost[temp.row][temp.column] + 1;
        }
        if (up.invalid(n, m) && !check[up.row][up.column])
        {
            Q.push(up);
            check[up.row][up.column] = true;
            timecost[up.row][up.column] = timecost[temp.row][temp.column] + 1;
        }
        day = timecost[temp.row][temp.column];
    }
    if (day == 0)
        cout << 0;
    else
    {
        if (tomato == cnt)
            cout << day;
        else
            cout << -1;
    }

    return 0;
}