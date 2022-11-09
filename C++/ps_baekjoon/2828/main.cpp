#include <bits/stdc++.h>
using namespace std;

int n, m, apple_ea, move_diff;
pair<int, int> bucket;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> apple_ea;
    bucket = {1, m};
    while (apple_ea--)
    {
        int lane;
        cin >> lane;
        if (lane < bucket.first)
        {
            int diff = bucket.first - lane;
            move_diff += diff;
            bucket.first -= diff;
            bucket.second -= diff;
        }
        else if (bucket.second < lane)
        {
            int diff = lane - bucket.second;
            move_diff += diff;
            bucket.first += diff;
            bucket.second += diff;
        }
    }
    cout << move_diff;
    return 0;
}