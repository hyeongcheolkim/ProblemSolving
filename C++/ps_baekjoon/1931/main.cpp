//baekjoon ps 1931

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

bool fnc(const pair<unsigned int, unsigned int> &obj1, const pair<unsigned int, unsigned int> &obj2)
{
    if(obj1.second!=obj2.second)
        return obj1.second < obj2.second;
    else
        return obj1.first < obj2.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    int cnt = 0;
    cin >> n;
    vector<pair<unsigned int, unsigned int>> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end(), fnc);
    for (int i = 0; i < n; i++)
    {
        static unsigned int endtime = 0;
        if(arr[i].first>=endtime)
        {
            endtime = arr[i].second;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}