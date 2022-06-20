#include <bits/stdc++.h>
using namespace std;

int n;
long long cnt;
vector<int> A, B, C, D, AB, CD;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (auto& e : vector<reference_wrapper<vector<int>>>{A, B, C, D})
        e.get().resize(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    AB.reserve(n * n);
    CD.reserve(n * n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            AB.push_back(A[i] + B[j]);
            CD.push_back(C[i] + D[j]);
        }
    sort(CD.begin(), CD.end());
    for (const auto& e : AB)
        if (binary_search(CD.begin(), CD.end(), -e))
        {
            int ea = upper_bound(CD.begin(), CD.end(), -e) - lower_bound(CD.begin(), CD.end(), -e);
            cnt += ea;
        }
    cout << cnt;
    return 0;
}