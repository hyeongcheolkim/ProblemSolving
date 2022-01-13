#include <bits/stdc++.h>
using namespace std;

int n, m, res;
vector<int> positive, negative;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    positive.reserve(n);
    negative.reserve(n);
    while (n--)
    {
        int num;
        cin >> num;
        if (num > 0)
            positive.push_back(num);
        else
            negative.push_back(-num);
    }
    sort(positive.begin(), positive.end(), greater<int>());
    sort(negative.begin(), negative.end(), greater<int>());
    for (int i = 0; i < positive.size(); i += m)
        res += positive[i] * 2;
    for (int i = 0; i < negative.size(); i += m)
        res += negative[i] * 2;
    int maxi = max(positive.empty() ? 0 : positive.front(), negative.empty() ? 0 : negative.front());
    cout << res - maxi;
    return 0;
}