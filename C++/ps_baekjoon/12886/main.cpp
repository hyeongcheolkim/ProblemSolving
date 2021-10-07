#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 5e2;
bool vst[mxN * 3 + 1][mxN * 3 + 1];
int a, b, c;
queue<pair<int, int>> q;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b >> c;
    int total = a + b + c;
    if (total % 3 != 0)
    {
        cout << 0;
        return 0;
    }
    vst[a][b] = true;
    q.emplace(a, b);
    while (!q.empty())
    {
        auto [a, b] = q.front();
        q.pop();
        int c = total - a - b;
        int temp[]{a, b, c};
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (temp[i] < temp[j])
                {
                    int num1 = temp[i] + temp[i];
                    int num2 = temp[j] - temp[i];
                    if (vst[num1][num2])
                        continue;
                    vst[num1][num2] = true;
                    q.emplace(num1, num2);
                }
    }
    cout << (vst[total / 3][total / 3] ? 1 : 0);
    return 0;
}