//baekjoon 3053 ps

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    const double pi = 3.14159265359;
    int n;
    cin >> n;

    cout << fixed << setprecision(6);
    cout << pi * pow(n, 2.0) << endl;
    cout << 2 * pow(n, 2.0);

    return 0;
}