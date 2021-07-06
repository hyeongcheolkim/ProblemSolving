//baekjoon ps 2448

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<char>> arr(n, vector<char>(2 * n - 1, ' '));
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            arr[i][n - 1 - j] = arr[i][n - 1 + j] = '*';
    function<void(int, int, int)> remove = [&](int start, int end, int center)
    {
        for (int row = end; row >= start; row--)
            for (int num = end - row; num >= 0; num--)
                arr[row][center - num] = arr[row][center + num] = ' ';
    };
    function<void(int, int, int)> recursion = [&](int start, int end, int center)
    {
        if (start + 1 == end - 1)
        {
            remove(start + 1, end - 1, center);
            return;
        }

        remove((start + end + 1) / 2, end, center);
        recursion(start, (start + end) / 2, center);
        recursion((start + end + 1) / 2, end, center + (end - start + 1) / 2);
        recursion((start + end + 1) / 2, end, center - (end - start + 1) / 2);
    };
    recursion(0, n - 1, n - 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
            cout << arr[i][j];
        cout << '\n';
    }
    return 0;
}