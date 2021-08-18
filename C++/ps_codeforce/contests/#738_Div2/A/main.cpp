//ps A

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> arr[i];
        int value = arr[1];
        for (int i = 1; i <= n; ++i)
            value = value & arr[i];
        cout << value << '\n';
    }
    return 0;
}