// ps number 2

#include <iostream>

using namespace std;

int sum(int n) { return n * (n + 1) / 2; }

int main()
{
    int a, b;
    int i = 0;
    cin >> a >> b;

    for (i = a; i < b;i++)
        cout << i << "+";
    cout << i << "=" << sum(b) - sum(a-1);

    return 0;
}
