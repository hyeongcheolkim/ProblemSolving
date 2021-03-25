// cpp algorithm ps number 40

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    auto arr1 = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    int m;
    cin >> m;
    auto arr2 = new int[m];
    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    vector<int> res;

    sort(&arr1[0], &arr1[n]);
    sort(&arr2[0], &arr2[m]);

    int cur1 = 0, cur2 = 0;

    while (cur1 < n && cur2 < m)
    {
        if (arr1[cur1] < arr2[cur2])
        {
            cur1++;
            continue;
        }
        else if (arr1[cur1] > arr2[cur2])
        {
            cur2++;
            continue;
        }

        else if (arr1[cur1] == arr2[cur2])
        {
            res.push_back(arr1[cur1]);
            cur1++;
            cur2++;
        }
    }

    for (const auto &e : res)
        cout << e << " ";
    return 0;
}