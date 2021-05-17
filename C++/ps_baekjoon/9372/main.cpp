//baekjoon ps 9372

#include <iostream>

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
        static int n, m;
        cin >> n >> m;
        while (m--)
        {
            static int a, b;
            cin >> a >> b;
        }
        cout << --n << '\n';
    }
    return 0;
}