//baekjoon ps 2981

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> sub(n - 1);
    set<int> res;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n - 1; i++)
        sub[i] = abs(arr[i] - arr[i + 1]);
    sort(sub.begin(), sub.end());
    int first = sub[0];
    int second;
    for (int i = 1; i <= n - 1; i++)
        if (first != sub[i])
        {
            second = sub[i];
            break;
        }
    while (true)
    {
        static int temp;
        if ((temp = second % first) == 0)
            break;
        second = first;
        first = temp;
    }
    for (int i = 2; i * i <= first; i++)
        if (first % i == 0)
        {
            res.insert(i);
            res.insert(first / i);
        }
    res.insert(first);
    for (const auto &e : res)
        cout << e << '\n';
    return 0;
}