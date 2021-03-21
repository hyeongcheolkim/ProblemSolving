// cpp algorithm ps number 4

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n=0;
    cin >> n;
    vector<int> arr;

    for (int i = 0; i < n;i++)
    {
        static int temp = 0;
        cin >> temp;
        arr.push_back(temp);
    }
    cout << *max_element(arr.begin(), arr.end()) - *min_element(arr.begin(), arr.end());

    return 0;
}