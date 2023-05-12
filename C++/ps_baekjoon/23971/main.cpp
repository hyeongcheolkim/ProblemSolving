#include <iostream>
#include <vector>
using namespace std;

long long h, w, n, m;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> h >> w >> n >> m;
    long long r = h / (n + 1);
    long long c = w / (m + 1);
    if (h % (n + 1) != 0)
        ++r;
    if (w % (m + 1) != 0)
        ++c;
    cout << r * c;
    return 0;
}