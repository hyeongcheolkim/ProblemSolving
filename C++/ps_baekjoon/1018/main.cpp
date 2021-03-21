//baekjoon 1018 ps

#include <iostream>

using namespace std;

int main()
{   
    // cin n m
    int n, m;
    cin >> n >> m;

    //allocate 2nd array n*m
    char **arr = new char *[n];
    for (int i = 0; i < n; i++)
        arr[i] = new char[m];

    //cin W or B to arr
    for (int row = 0; row < n; row++)
        for (int column = 0; column < m; column++)
            cin >> arr[row][column];

    //declare value
    int recolor = 0;
    unsigned int min = 4'294'967'295; //assign unsigned int MAXIMUM

    //algorithm
    for (int cursor_row = 0; cursor_row <= n - 8; cursor_row++)
        for (int cursor_column = 0; cursor_column <= m - 8; cursor_column++)
        {
            recolor = 0;
            for (int row = cursor_row; row < cursor_row + 8; row++)
                for (int column = cursor_column; column < cursor_column + 8; column++)
                {
                    if ((row + column) % 2 == 0 && arr[row][column] == 'B')
                        recolor++;
                    if ((row + column) % 2 == 1 && arr[row][column] == 'W')
                        recolor++;
                }
            recolor = recolor > 32 ? 64 - recolor:recolor;
            if (recolor <min)
                min = recolor;
        }

    cout << min;

    return 0;
}