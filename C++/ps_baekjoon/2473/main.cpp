//baekjoon ps 2473

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
#include <array>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long mini = numeric_limits<long long>::max();
    int n;
    cin >> n;
    vector<long long> liquid(n);
    array<int, 3> res;
    for (int i = 0; i < n; i++)
        cin >> liquid[i];
    sort(liquid.begin(), liquid.end());
    for (int ptr0 = 0; ptr0 < liquid.size(); ptr0++)
    {
        int ptr1 = ptr0 + 1;
        int ptr2 = liquid.size() - 1;
        while (ptr1 < ptr2)
        {
            long long sum = liquid[ptr0] + liquid[ptr1] + liquid[ptr2];
            if (abs(sum) < mini)
            {
                mini = abs(sum);
                res[0] = liquid[ptr0];
                res[1] = liquid[ptr1];
                res[2] = liquid[ptr2];
            }
            if (sum < 0)
                ptr1++;
            else
                ptr2--;
        }
    }
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << ' ';
    return 0;
}