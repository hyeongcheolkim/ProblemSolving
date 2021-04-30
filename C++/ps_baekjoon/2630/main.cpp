//baekjoon ps 2630

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n, w, b;

void divide(int num, pair<int, int> pos1, pair<int, int> pos2, const vector<vector<int>> &arr)
{
    if (num == 0)
        return;
    for (int i = pos1.first; i < pos2.first; i += num)
        for (int j = pos1.second; j < pos2.second; j += num)
        {
            static int sum;
            sum = 0;
            for (int row = i; row < i + num; row++)
                for (int column = j; column < j + num; column++)
                    sum += arr[row][column];
            if (sum == num * num)
                b++;
            else if (sum == 0)
                w++;
            else
                divide(num/2, {i, j}, {i + num, j + num}, arr);
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    divide(n, {0, 0}, {n, n}, arr);
    cout << w << '\n';
    cout << b << '\n';
    return 0;
}