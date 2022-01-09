#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e2;
int n, l, cnt, board[mxN + 2][mxN + 2];

bool solve(const vector<int>&& arr)
{
    static bool vst[mxN];
    memset(vst, false, sizeof(vst));
    for (int idx = 0; idx < n - 1; ++idx)
    {
        switch (bool flag = true; arr[idx] - arr[idx + 1])
        {
            case 0:
                continue;
                break;
            case 1:
                if (idx + l >= n)
                    return false;
                for (int i = 0; i < l; ++i)
                    flag &= !vst[idx + 1 + i] & arr[idx + 1] == arr[idx + 1 + i];
                if (flag)
                {
                    for (int i = 0; i < l; ++i)
                        vst[idx + 1 + i] = true;
                }
                else
                    return false;
                break;
            case -1:
                if (idx + 1 - l < 0)
                    return false;
                for (int i = 0; i < l; ++i)
                    flag &= !vst[idx - i] & arr[idx] == arr[idx - i];
                if (flag)
                {
                    for (int i = 0; i < l; ++i)
                        vst[idx - i] = true;
                }
                else
                    return false;
                break;
            default:
                return false;
                break;
        }
    }
    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> l;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> board[i][j];
    for (int i = 1; i <= n; ++i)
    {
        vector<int> arr;
        arr.reserve(n);
        for (int j = 1; j <= n; ++j)
            arr.push_back(board[i][j]);
        cnt += solve(move(arr));
    }
    for (int j = 1; j <= n; ++j)
    {
        vector<int> arr;
        arr.reserve(n);
        for (int i = 1; i <= n; ++i)
            arr.push_back(board[i][j]);
        cnt += solve(move(arr));
    }
    cout << cnt;
    return 0;
}