#include <bits/stdc++.h>
using namespace std;

int n, k;
list<int> lt;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    lt.resize(n);
    iota(lt.begin(), lt.end(), 1);
    cout << '<';
    for (int i = 1; !lt.empty(); ++i)
    {
        if (lt.size() == 1)
        {
            cout << lt.front() << '>';
            break;
        }
        if (i % k == 0)
            cout << lt.front() << ", ";
        else
            lt.push_back(lt.front());
        lt.pop_front();
    }
    return 0;
}