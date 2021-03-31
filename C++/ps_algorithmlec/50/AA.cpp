// cpp algorithm ps number 50

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int row, column;
    int h, w;
    int max = -1;
    cin >> row >> column;
    vector<vector<int>> arr(row, vector<int>(column));
    for (auto &e1 : arr)
        for (auto &e2 : e1)
            cin >> e2;
    cin >> h >> w;
    for (int i = 0; i <= row - h; i++)
        for (int j = 0; j <= column -w; j++)
        {
            static int total;
            total = 0;
            for (int x = i; x < i + h; x++)
                for (int y = j; y < j + w; y++)
                    total += arr[x][y];
            if(total>max)
                max = total;
        }
    cout << max;

    return 0;
}