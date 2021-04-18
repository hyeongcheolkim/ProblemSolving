//baekjoon ps 2580

#include <iostream>

using namespace std;

int map[10][10];
bool row[10][10];
bool col[10][10];
bool area[10][10];

void dfs(int level)
{
    if (level == 81)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << map[i][j] << ' ';
            cout << '\n';
        }
        exit(0);
    }

    int level_row = level / 9;
    int level_col = level % 9;

    if (map[level_row][level_col])
        dfs(level + 1);
    else
        for (int i = 1; i <= 9; i++)
        {
            if (!col[level_col][i] && !row[level_row][i] && !area[(level_row / 3) * 3 + level_col / 3][i])
            {
                map[level_row][level_col] = i;
                col[level_col][i] = true;
                row[level_row][i] = true;
                area[(level_row / 3) * 3 + level_col / 3][i] = true;
                dfs(level + 1);
                map[level_row][level_col] = 0;
                col[level_col][i] = false;
                row[level_row][i] = false;
                area[(level_row / 3) * 3 + level_col / 3][i] = false;
            }
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            cin >> map[i][j];
            if (map[i][j])
            {
                col[j][map[i][j]] = true;
                row[i][map[i][j]] = true;
                area[(i / 3) * 3 + j / 3][map[i][j]] = true;
            }
        }
    dfs(0);
    return 0;
}