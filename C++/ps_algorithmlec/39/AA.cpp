// cpp algorithm ps number 39

#include <iostream>

using namespace std;

int main()
{
    int n, m;
    bool arr1End = true, arr2End = true;

    cin >> n;
    auto arr1 = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    cin >> m;
    auto arr2 = new int[m];
    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    auto res = new int[n + m]{0};

    while (arr1End || arr2End)
    {
        static int cur1 = 0, cur2 = 0, curRes = 0;
        while (arr1End && arr2End)
        {
            if (arr1[cur1] <= arr2[cur2])
                res[curRes++] = move(arr1[cur1++]);

            if (arr1[cur1] > arr2[cur2])
                res[curRes++] = move(arr2[cur2++]);

            if (cur1 == n)
                arr1End = false;
            if (cur2 == m)
                arr2End = false;
        }

        if (arr1End)
            res[curRes++] = move(arr1[cur1++]);
        if (arr2End)
            res[curRes++] = move(arr2[cur2++]);
            
        if (cur1 == n)
            arr1End = false;
        if (cur2 == m)
            arr2End = false;
    }

    for (int i = 0; i < (n + m); i++)
        cout << res[i];

    return 0;
}