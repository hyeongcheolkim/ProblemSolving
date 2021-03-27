// cpp algorithm ps number 42

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, key;
    cin >> n >> key;

    vector<int> arr(n);
    for (auto &e:arr)
        cin >> e;

    sort(arr.begin(), arr.end());

    int mid, lt=0, rt=n-1;
    while(true)
    {
        mid = (lt + rt) / 2;
        if(arr[mid]==key)
            break;
        else if(arr[mid]>key)
            rt = mid - 1;
        else if(arr[mid]<key)
            lt = mid + 1;
    }
    cout << mid+1;
    return 0;
}