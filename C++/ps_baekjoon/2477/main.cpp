#include <bits/stdc++.h>
using namespace std;

int k;
vector<pair<int, int>> arr;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> k;
    int big_width = 0, big_height = 0, small_square_area = 0;
    for (int i = 0; i < 6; ++i)
    {
        int direction, length;
        cin >> direction >> length;
        if (direction <= 2)
            big_width += length;
        else
            big_height += length;
        arr.emplace_back(direction, length);
    }
    big_width /= 2;
    big_height /= 2;
    for (int i = 0; i < 6; ++i)
    {
        const auto& [now_direction, now_length] = arr[i];
        if (now_length == big_width || now_length == big_height)
        {
            const auto& [next_direction, next_length] = arr[(i + 5) % 6];
            if (next_length == big_width || next_length == big_height)
                small_square_area = arr[(i + 2) % 6].second * arr[(i + 3) % 6].second;
        }
    }
    cout << k * (big_height * big_width - small_square_area);
    return 0;
}