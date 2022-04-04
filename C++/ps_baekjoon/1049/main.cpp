#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    int package_min = INF, individual_min = INF;
    while (m--)
    {
        int package, individual;
        cin >> package >> individual;
        package_min = min(package_min, package);
        individual_min = min(individual_min, individual);
    }
    if (package_min < individual_min * 6)
        cout << (n / 6) * package_min + min((n % 6) * individual_min, package_min);
    else
        cout << n * individual_min;
    return 0;
}