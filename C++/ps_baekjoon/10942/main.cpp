//baekjoon ps 10942

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> memo(2001, vector<int>(2001, -1));
vector<int> arr;

int recursion(int s, int e)
{
    if (memo[s][e] != -1)
        return memo[s][e];
    if (s < e)
    {
        if (arr[s] == arr[e])
            return memo[s][e] = recursion(s + 1, e - 1);
        else if (arr[s] != arr[e])
            return memo[s][e] = 0;
    }
    else
        return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    arr = vector<int>(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    int m;
    cin >> m;
    while (m--)
    {
        int s, e;
        cin >> s >> e;
        cout << recursion(s, e) << '\n';
    }
    return 0;
}