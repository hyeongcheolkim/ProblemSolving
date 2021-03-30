// cpp algorithm ps number 46

#include <iostream>
#include <vector>

using namespace std;

main()
{
    int n, k, index = 1, cnt = 0;
    bool flag = true;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    cin >> k;
    
    while (true)
    {
        while (arr[index] == 0)
        {
            index++;
            if (index > n)
                index = index%n;
            if (cnt == k)
            {
                flag = false;
                break;
            }
        }
        if (arr[index]-- == 1)
            cnt++;

        if (--k == 0)
            break;
        index++;
        if (index > n)
            index = index%n;
    }
    if (cnt==n)
        cout << -1;
    else
        cout << index;
    return 0;
}