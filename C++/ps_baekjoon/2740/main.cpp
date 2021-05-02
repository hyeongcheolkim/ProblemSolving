//baekjoon ps 2740

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];
    cin >> m >> k;
    vector<vector<int>> B(m, vector<int>(k));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++)
            cin >> B[i][j];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            static int res;
            res = 0;
            for (int x = 0; x < A[i].size(); x++)
                res += A[i][x] * B[x][j];
            cout << res << " ";
        }
        cout << '\n';
    }
    return 0;
}