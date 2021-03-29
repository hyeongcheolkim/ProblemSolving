// cpp algorithm ps number 43

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

int main()
{
    int n, m;
    int total = 0, min = INT_MAX;
    int lt, rt, mid;
    cin >> n >> m;
    vector<int> arr(n);

    for (auto &e : arr)
    {
        cin >> e;
        total += e;
    }

    vector<int> cmp(total);
    for (int i = 0; i < total; i++)
        cmp[i] = i + 1;

    lt = 0;
    rt = total-1;

    while (lt <= rt)
    {
        static int disc;
        static int index;
        disc = 0;
        index = 0;
        mid = (lt + rt) / 2;
        while (index != n)
        {
            static int tempsum;
            tempsum = 0;
            while (tempsum + arr[index] <= cmp[mid]&&index<n)
                tempsum += arr[index++];
            disc++;
        }
        if(disc<=m)
        {
            if(cmp[mid]<min)
                min = cmp[mid];
            rt = mid - 1;
        }
        else if(disc>m)
            lt = mid + 1;
    }
    cout << min;
}