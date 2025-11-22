#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> arr;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    int good_count = 0;

    for (int i = 0; i < n; ++i)
    {
        int target = arr[i];
        int start = 0;
        int end = n - 1;

        while (start < end)
        {
            int current_sum = arr[start] + arr[end];

            if (current_sum == target)
            {
                if (start != i && end != i)
                {
                    ++good_count;
                    break;
                }
                else if (start == i)
                {
                    ++start;
                }
                else
                {
                    --end;
                }
            }
            else if (current_sum < target)
            {
                ++start;
            }
            else
            {
                --end;
            }
        }
    }

    cout << good_count;
    return 0;
}