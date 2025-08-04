#include <bits/stdc++.h>
using namespace std;

int n, total, answer;
vector<int> acc;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    acc.resize(n);
    int maxi = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> acc[i];
        total += acc[i];
        if (i != 0 && i != n - 1)
        {
            maxi = max(maxi, acc[i]);
        }
    }
    answer = total - acc.front() - acc.back() + maxi;

    for (int i = 1; i < n; ++i)
    {
        static int minus_acc = 0;
        minus_acc += acc[i - 1];

        int honey = 2 * total;
        honey -= acc[0];
        honey -= 2 * acc[i];
        honey -= minus_acc;

        answer = max(answer, honey);
    }
    reverse(acc.begin(), acc.end());
    for (int i = 1; i < n; ++i)
    {
        static int minus_acc = 0;
        minus_acc += acc[i - 1];

        int honey = 2 * total;
        honey -= acc[0];
        honey -= 2 * acc[i];
        honey -= minus_acc;

        answer = max(answer, honey);
    }
    cout << answer;
    return 0;
}