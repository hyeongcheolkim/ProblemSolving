//baekjoon ps 1676

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int two = 0;
    int five = 0;
    for (int i = 2; i <= n; i += 2)
    {
        static int temp;
        temp = i;
        while (true)
        {
            if (temp % 2 == 0)
            {
                two++;
                temp /= 2;
            }
            else
                break;
        }
    }
    for (int i = 5; i <= n; i += 5)
    {
        static int temp;
        temp = i;
        while (true)
        {
            if (temp % 5 == 0)
            {
                five++;
                temp /= 5;
            }
            else
                break;
        }
    }
    cout << min(two,five);
    return 0;
}