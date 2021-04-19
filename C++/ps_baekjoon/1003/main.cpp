//baekjoon ps 1003

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int cnt0[45];
    int cnt1[45];
    int n;
    cin >> n;
    cnt0[0] = 1;
    cnt1[0] = 0;
    cnt0[1] = 0;
    cnt1[1] = 1;
    for (int i = 2; i <= 40; i++)
    {
        cnt0[i] = cnt0[i - 1] + cnt0[i - 2];
        cnt1[i] = cnt1[i - 1] + cnt1[i - 2];
    }
    while (n--)
    {
        static int x;
        cin >> x;
        cout << cnt0[x] << " " << cnt1[x] << '\n';
    }
    return 0;
}