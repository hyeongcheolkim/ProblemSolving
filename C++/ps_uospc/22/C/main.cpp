#include <bits/stdc++.h>
using namespace std;

int q, k;
vector<int> mini, maxi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> q >> k;
    while (q--)
    {
        static int acc = 0;
        int d, p;
        cin >> d >> p;
        acc += d;
        int cut = (p ? k : k - 1);
        if (p)
            mini.push_back(cut - acc);
        else
            maxi.push_back(cut - acc);
    }
    cout << *max_element(mini.begin(), mini.end()) << ' ';
    cout << *min_element(maxi.begin(), maxi.end());
    return 0;
}