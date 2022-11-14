#include <bits/stdc++.h>
using namespace std;

int n;
vector<bool> vst;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vst.resize(n);
    while (n--)
    {
        int num;
        cin >> num;
        if (vst[num])
        {
            cout << num;
            exit(0);
        }
        vst[num] = true;
    }
    return 0;
}