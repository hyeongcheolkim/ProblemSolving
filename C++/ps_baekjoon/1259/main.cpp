//baekjoon ps 1259

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string input, temp;
    while (true)
    {
        cin >> input;
        if (input == "0")
            break;
        temp = input;
        reverse(input.begin(), input.end());
        if (temp == input)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
    return 0;
}