//baekjoon ps 10974

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        arr[i] = i;
    function<int(int)> factorial = [&](int n) -> int
    { return (n == 1 || n == 0) ? 1 : n * factorial(n - 1); };
    int cnt = factorial(n);
    while (cnt--)
    {
        for (int i = 1; i <= n; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        next_permutation(arr.begin() + 1, arr.end());
    }
    return 0;
}