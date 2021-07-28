//baekjoon ps 3036

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int firstring, tempring;
    cin >> n;
    cin >> firstring;
    n--;
    while (n--)
    {
        static int input, first;
        first = firstring;
        cin >> input;
        tempring = input;
        while (true)
        {
            static int temp;
            if ((temp = first % input) != 0)
            {
                first = input;
                input = temp;
            }
            else
                break;
        }
        cout << firstring / input << "/" << tempring / input << '\n';
    }
    return 0;
}