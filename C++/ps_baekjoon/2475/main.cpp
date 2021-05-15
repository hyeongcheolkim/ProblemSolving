//baekjoon ps 2475

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int res=0;
    for (int i = 0; i < 5;i++)
    {
        static int input;
        cin >> input;
        res += ((input % 10) * (input % 10)) % 10;
        res %= 10;
    }
    cout << res;
    return 0;
}