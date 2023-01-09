#include <bits/stdc++.h>
using namespace std;

constexpr int SIZE = 9;
vector<int> arr;
int diff = -100;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    arr.resize(SIZE);
    for (int i = 0; i < SIZE; ++i)
    {
        cin >> arr[i];
        diff += arr[i];
    }
    sort(arr.begin(), arr.end());
    [&]
    {
        for (int i = 0; i < SIZE; ++i)
            for (int j = i + 1; j < SIZE; ++j)
                if (arr[i] + arr[j] == diff)
                {
                    for (int k = 0; k < SIZE; ++k)
                    {
                        if (k == i || k == j)
                            continue;
                        cout << arr[k] << '\n';
                    }
                    return;
                }
    }();
    return 0;
}