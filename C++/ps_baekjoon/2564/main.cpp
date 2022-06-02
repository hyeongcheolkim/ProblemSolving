#include<bits/stdc++.h> 
using namespace std;

int row, col, n, res;
vector<int> store;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> col >> row >> n;
    store.reserve(n);
    ++n;
    while (n--)
    {
        int direct, dist;
        cin >> direct >> dist;
        if (direct == 2)
            dist = row + col + (col - dist);
        if (direct == 3)
            dist = 2 * col + row + (row - dist);
        if (direct == 4)
            dist = col + dist;
        store.push_back(dist);
    }
    int guard = store.back();
    store.pop_back();
    for (const int perimeter = 2 * row + 2 * col; const auto & e : store)
    {
        int diff = abs(guard - e);
        res += min(diff, perimeter - diff);
    }
    cout << res;
    return 0;
}