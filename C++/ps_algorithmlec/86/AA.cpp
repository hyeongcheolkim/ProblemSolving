// cpp algorithm ps number 86

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

typedef struct pos
{
    int row, column;
    pos(const int &row, const int &column)
    {
        this->row = row;
        this->column = column;
    }
    int distance(const pos &obj)
    {
        return abs(this->row - obj.row) + abs(this->column - obj.column);
    }
} pos;

int n, m;
vector<pos> house;
vector<pos> pizza;
int finalmini = INT_MAX;

void dfs(int index, int level, vector<int> &ref)
{
    if (level == m)
    {
        int sum = 0;
        for (int j = 0; j < house.size(); j++)
        {
            static int min;
            min = INT_MAX;
            for (int i = 0; i < m; i++)
                if (min > house[j].distance(pizza[ref[i]]))
                    min = house[j].distance(pizza[ref[i]]);
            sum += min;
        }
        if (finalmini > sum)
            finalmini = sum;
        return;
    }
    for (int i = index; i < pizza.size(); i++)
    {
        ref[level] = i;
        dfs(i + 1, level + 1, ref);
    }
}

int main()
{
    cin >> n >> m;
    for (int row = 1; row <= n; row++)
        for (int column = 1; column <= n; column++)
        {
            static int temp;
            cin >> temp;
            if (temp == 1)
                house.push_back(pos(row, column));
            if (temp == 2)
                pizza.push_back(pos(row, column));
        }
    vector<int> ref(m);
    dfs(0, 0, ref);
    cout << finalmini;
    return 0;
}