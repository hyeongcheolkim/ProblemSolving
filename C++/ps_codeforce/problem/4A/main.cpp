//codeforce ps 4A

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    if (n % 2 == 1 || n == 2)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}