//baekjoon ps 9375

#include <iostream>
#include <string>
#include <utility>
#include <map>

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
        int n, res = 1;
        cin >> n;
        map<string, int> arr;
        while (n--)
        {
            static string temp;
            cin >> temp >> temp;
            if (arr.find(temp) == arr.end())
                arr[temp] = 1;
            else
                arr[temp]++;
        }
        for (const auto &e : arr)
            res *= e.second + 1;
        cout << res - 1 << '\n';
    }
    return 0;
}