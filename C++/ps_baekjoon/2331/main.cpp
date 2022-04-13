#include <bits/stdc++.h>
using namespace std;

vector<int> vst;
int a, p;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> p;
    vst.resize(int(pow(10, 5) * 4));
    while (vst[a] <= 2)
    {
        ++vst[a];
        string str = to_string(a);
        a = 0;
        for (const auto& e : str)
            a += pow((e - '0'), p);
    }
    cout << count(vst.begin(), vst.end(), 1);
    return 0;
}