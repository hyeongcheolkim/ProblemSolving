#include <bits/stdc++.h>
using namespace std;

string x;
int cnt = 0;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> x;
    while (x.size() > 1)
    {
        ++cnt;
        int sum = 0;
        for (const auto& e : x)
            sum += e - '0';
        x = to_string(sum);
    }
    cout << cnt << '\n';
    cout << (stoi(x) % 3 == 0 ? "YES" : "NO");
    return 0;
}