#include <bits/stdc++.h>
using namespace std;

int n;
long long score;
vector<int> predict, actual;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    predict.resize(n);
    actual.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> predict[i];
    sort(predict.begin(), predict.end());
    iota(actual.begin(), actual.end(), 1);
    for (int i = 0; i < n; ++i)
        score += abs(predict[i] - actual[i]);
    cout << score;
    return 0;
}