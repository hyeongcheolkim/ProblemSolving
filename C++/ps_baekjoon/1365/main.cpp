//baekjoon ps 1365

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> lcs;
    lcs.reserve(n);
    lcs.push_back(0);
    for (int i = 0; i < n; ++i)
    {
        int now;
        cin >> now;
        if (lcs.back() < now)
            lcs.push_back(now);
        else
            *lower_bound(lcs.begin(), lcs.end(), now) = now;
    }
    cout << n - (lcs.size() - 1);
    return 0;
}