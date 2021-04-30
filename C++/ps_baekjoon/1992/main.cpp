//baekjoon ps 1992

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string res = "";

void divide(int num, pair<int, int> pos1, pair<int, int> pos2, const vector<vector<char>> &arr)
{
    if (num == 0)
        return;
    num /= 2;
    res += '(';
    for (int i = pos1.first; i < pos2.first; i += num)
        for (int j = pos1.second; j < pos2.second; j += num)
        {
            static int sum;
            sum = 0;
            for (int row = i; row < i + num; row++)
                for (int column = j; column < j + num; column++)
                    sum += arr[row][column] - '0';
            if (sum == num * num)
                res += '1';
            else if (sum == 0)
                res += '0';
            else
                divide(num, {i, j}, {i + num, j + num}, arr);
        }
    res += ')';
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    int sum = 0;
    cin >> n;
    vector<vector<char>> arr(n, vector<char>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            sum += arr[i][j]-'0';
        }
    if (sum == n * n)
        res += "1";
    else if (sum == 0)
        res += "0";
    else
        divide(n, {0, 0}, {n, n}, arr);
    cout << res;
    return 0;
}