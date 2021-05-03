//baekjoon ps 10816

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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
        int rt = arr.size()-1;
        int mid;
        int res;
        while (lt <= rt)
        {
            mid = (lt + rt) / 2;
            if (arr[mid] <= e)
                lt = mid + 1;
            else
                rt = mid - 1;
        }
        cout << "1: " << lt<<" "<<rt << '\n';
        lt = 0;
        rt = arr.size()-1;
        mid;
        while (lt <= rt)
        {
            mid = (lt + rt) / 2;
            if (arr[mid] < e)
                lt = mid + 1;
            else
                rt = mid - 1;
        }
        cout << "2: " << lt <<" "<<rt << '\n';
    }
    return 0;
}