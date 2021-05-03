//baekjoon ps 1920

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n;
    vector<int> arr(n);
    for (auto &e : arr)
        cin >> e;
    sort(arr.begin(), arr.end());
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        static int input;
        cin >> input;
        cout << binary_search(arr.begin(),arr.end(),input)<<'\n';
    }
    return 0;
}