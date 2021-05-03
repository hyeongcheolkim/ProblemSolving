//baekjoon ps 10816

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n;
    vector<int> arr(n);
    for (auto &e : arr)
        cin >> e;
    cin >> m;
    vector<int> data(m);
    for (auto &e : data)
        cin >> e;
    sort(arr.begin(), arr.end());

    for (const auto &e : data)
    {
        int lt = 0;
        int rt = arr.size();
        int mid;
        int res;
        while (lt < rt)
        {
            mid = (lt + rt) / 2;
            if (arr[mid] <= e)
                lt = mid + 1;
            else
                rt = mid;
        }
        res = rt;
        lt = 0;
        rt = arr.size();
        mid;
        while (lt < rt)
        {
            mid = (lt + rt) / 2;
            if (arr[mid] < e)
                lt = mid + 1;
            else
                rt = mid;
        }
        cout << res-rt << '\n';
    }

    return 0;
}