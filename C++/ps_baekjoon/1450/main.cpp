//baekjoon ps 1450

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, c;
    int cnt = 0;
    cin >> n >> c;
    vector<int> left, right;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    function<void(int, int, int, vector<int>&)> dfs = [&](int lt, int rt, int sum, vector<int> &v)
    {
        if (sum > c)
            return;
        if (lt > rt)
            return v.push_back(sum);
        dfs(lt + 1, rt, sum, v);
        dfs(lt + 1, rt, sum + arr[lt], v);
    };
    dfs(0, n / 2 - 1, 0, left);
    dfs(n / 2, n - 1, 0, right);
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    int ptr_right = right.size() - 1;
    for (int ptr_left = 0; ptr_left < left.size(); ptr_left++)
    {
        while(ptr_right>=0 && left[ptr_left]+right[ptr_right]>c)
            ptr_right--;
        cnt += ptr_right + 1;
    }
    cout << cnt;
    return 0;
}