//baekjoon ps 5086

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (true)
    {
        static int a, b;
        cin >> a >> b;
        if (a == 0 & b == 0)
            break;
        if ((b / a) * a == b)
            cout << "factor"<<'\n';
        else if ((a / b) * b == a)
            cout << "multiple"<<'\n';
        else
            cout << "neither"<<'\n';
    }
    return 0;
}