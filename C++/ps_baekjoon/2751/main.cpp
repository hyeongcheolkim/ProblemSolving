//baekjoon 2751 ps

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> arr;
    unsigned int n;
    cin >> n;

    while(n--)
    {
        static int num = 0;
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());

    for (const auto &e:arr)
        cout << e<<'\n';

        return 0;
}