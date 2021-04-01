// cpp algorithm ps number 51

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int row, column;
    int h, w;
    int max = -1;
    int first = 0;
    cin >> row >> column;

    vector<vector<int>> arr(row, vector<int>(column));
    vector<vector<int>> dp(row, vector<int>(column));

    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
        {
            cin >> arr[i][j];
            dp[i][j] = arr[i][j] + (i-1>=0?dp[i - 1][j]:0)+ (j-1>=0?dp[i][j - 1]:0) - (i-1>=0&&j-1>=0?dp[i - 1][j - 1]:0);
        }
    cin >> h >> w;

    for (int i = h - 1; i < row; i++)
        for (int j = w - 1; j < column; j++)
        {
            static int sum;
            sum = dp[i][j] - (i-h>=0?dp[i - h][j]:0) - (j-w>=0?dp[i][j - w]:0) + (i-h>=0&&j-w>=0?dp[i - h][j - w]:0);
            if (max < sum)
                max = sum;
        }

    cout << max;

    return 0;
}