//baekjoon ps 1208

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <limits>

using namespace std;

void dfs(int idx, const vector<int> &arr, map<long long,long long> &map, int sum)
{
    if (idx == arr.size())
    {
        map[sum]++;
        return;
    }
    dfs(idx + 1, arr, map, sum);
    dfs(idx + 1, arr, map, sum + arr[idx]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, s;
    long long cnt = 0;
    cin >> n >> s;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> arr1, arr2;
    arr1.assign(arr.begin(), arr.begin() + n / 2);
    arr2.assign(arr.begin() + n / 2, arr.end());
    map<long long, long long> map1, map2;
    dfs(0, arr1, map1, 0);
    dfs(0, arr2, map2, 0);
    map2[numeric_limits<long long>::min()] = 0;
    auto iter1 = map1.begin();
    auto iter2 = --map2.end();
    long long sum = iter1->first + iter2->first;
    while (iter1 != map1.end() && iter2 != map2.begin())
    {
        if (s == sum)
            cnt += (iter1++)->second * iter2->second;
        else if (s > sum)
            iter1++;
        else if (s < sum)
            iter2--;
        sum = iter1->first + iter2->first;
    }
    if (s == 0)
        cnt--;
    cout << cnt;
}