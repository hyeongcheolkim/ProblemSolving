#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        while (n--)
        {
            char input;
            cin >> input;
            switch (input)
            {
            case 'U':
                cout << 'D';
                break;
            case 'D':
                cout << 'U';
                break;
            case 'L':
                cout << 'L';
                break;
            case 'R':
                cout << 'R';
                break;
            }
        }
        cout << '\n';
    }
    return 0;
}