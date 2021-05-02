//baekjoon ps 10830

#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;
typedef vector<vector<ull>> matrix;

constexpr ull M = 1000;
ull n, b;

matrix multiply(const matrix &A, const matrix &B)
{
    matrix res(n, vector<ull>(n, 0));
    for (ull i = 0; i < n; i++)
        for (ull j = 0; j < n; j++)
            for (ull x = 0; x < n; x++)
            {
                res[i][j] += (A[i][x] % M * B[x][j] % M) % M;
                res[i][j] %= M;
            }
    return res;
}

matrix bfs(matrix A, ull exp)
{
    matrix res(n, vector<ull>(n, 0));
    for (int i = 0; i < n; i++)
        res[i][i] = 1;
    while (exp)
    {
        if (exp % 2 == 1)
            res = multiply(res, A);
        exp /= 2;
        A = multiply(A, A);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> b;
    matrix A(n, vector<ull>(n));
    for (ull i = 0; i < n; i++)
        for (ull j = 0; j < n; j++)
            cin >> A[i][j];
    auto res = bfs(A, b);
    for (ull i = 0; i < n; i++)
    {
        for (ull j = 0; j < n; j++)
            cout << res[i][j] << " ";
        cout << '\n';
    }
    return 0;
}