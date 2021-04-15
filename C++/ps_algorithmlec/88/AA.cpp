// cpp algorithm ps number 88

#include <iostream>
#include <vector> 
#include <queue>
#include <array>
using namespace std;

typedef struct pos
{
    int row, column;
    pos(const int&row, const int &column)
    {
        this->row = row;
        this->column = column;
    }
    bool operator ==(const pos &obj) const
    {
        if(this->row==row && this->column ==column)
            return true;
        else
            return false;
    }
    bool operator !=(const pos &obj) const
    {
        if(this->row!=row || this->column !=column)
            return true;
        else
            return false;
    }
} pos;

int main()
{
    int cnt = 0;
    vector<vector<int>> map(9, vector<int>(9, 1));
    vector<vector<int>> cost(9, vector<int>(9, 0));
    for (int i = 1; i <= 7;i++)
        for (int j = 1; j <= 7;j++)
            cin >> map[i][j];

    queue<pos> Q;
    Q.push(pos(1,1));
    cost[1][1] = 0;
    while((!Q.empty())||(Q.front()!=pos(7,7)))
    {
        pos left = pos(Q.front().row, Q.front().column-1);
        pos right = pos(Q.front().row, Q.front().column+1);
        pos down = pos(Q.front().row+1, Q.front().column);
        pos up = pos(Q.front().row-1, Q.front().column);
        array<pos, 4> poslist = {left, right, down, up};
        for (const auto &e:poslist)
            if(map[e.row][e.column]==0)
            {
                Q.push(e);
                cost[e.row][e.column] = cost[Q.front().row][Q.front().column] + 1;
            }
        map[Q.front().row][Q.front().column] = 1;
        Q.pop();
    }
    if(cost[7][7]!=0)
        cout << cost[7][7];
    else
        cout << -1;
    return 0;
}