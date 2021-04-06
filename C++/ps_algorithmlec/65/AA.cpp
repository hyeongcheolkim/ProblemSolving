// cpp algorithm ps number 65

#include <iostream>

using namespace std;
constexpr int SIZE = 8;
int map[SIZE][SIZE];
bool trace[SIZE][SIZE];
int cnt = 0;

void fnc(int x, int y)
{
    trace[x][y] = true;
    if (map[x][y] == 1)
        return;
    if (x == 7 && y == 7)
    {
        cnt++;
        return;
    }
    if (7 >= x + 1 && x + 1 >= 1 && !trace[x + 1][y])
    {
        fnc(x + 1, y);
        trace[x + 1][y] = false;
    }
    if (7 >= x - 1 && x - 1 >= 1 && !trace[x - 1][y])
    {
        fnc(x - 1, y);
        trace[x - 1][y] = false;
    }
    if (7 >= y + 1 && y + 1 >= 1 && !trace[x][y + 1])
    {
        fnc(x, y + 1);
        trace[x][y + 1] = false;
    }
    if (7 >= y - 1 && y - 1 >= 1 && !trace[x][y - 1])
    {
        fnc(x, y - 1);
        trace[x][y - 1] = false;
    }
}

int main()
{
    for (int i = 1; i <= 7; i++)
        for (int j = 1; j <= 7; j++)
            cin >> map[i][j];
    fnc(1, 1);
    cout << cnt;
    return 0;
}