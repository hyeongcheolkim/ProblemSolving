//baekjoon ps 11444

#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long ull;
typedef vector<vector<ull>> matrix;

constexpr ull M = 1000000007;
constexpr ull n = 2;

matrix multiply(const matrix &A, const matrix &B)
{
    matrix res(n, vector<ull>(n, 0));
    for (ull i = 0; i < n; i++)
        for (ull j = 0; j < n; j++)
        {
            for (ull x = 0; x < n; x++)
                res[i][j] += (A[i][x] * B[x][j]) % M;
            res[i][j] %= M;
        }
    return res;
}

matrix bfs(matrix A, ull exp)
{
    matrix res(n, vector<ull>(n, 0));
    for (ull i = 0; i < n; i++)
        res[i][i] = 1;
    while (exp > 0)
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
    ull num;
    cin >> num;
    matrix A = {{0, 0}, {1, 1}};
    matrix E = {{0, 1}, {1, 1}};
    matrix res(n, vector<ull>(n));
    E = bfs(E, num);
    cout << multiply(E, A)[0][1];
    return 0;
}