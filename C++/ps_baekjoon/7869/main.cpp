//baekjoon ps 7869

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    constexpr double PI = 3.14159265358979;
    ios_base::sync_with_stdio(false);
    double x1, y1, r1, x2, y2, r2, res;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    if (r1 < r2)
    {
        swap(x1, x2);
        swap(y1, y2);
        swap(r1, r2);
    }
    if (dist >= r1 + r2)
        res = 0.0;
    else if (dist + r2 <= r1)
        res = pow(r2, 2) * PI;
    else
    {
        double theta1 = acos((pow(r1, 2) + pow(dist, 2) - pow(r2, 2)) / (2 * r1 * dist));
        double theta2 = acos((pow(r2, 2) + pow(dist, 2) - pow(r1, 2)) / (2 * r2 * dist));
        double s1 = (pow(r1, 2) * 2 * theta1) / 2 - pow(r1, 2) * sin(2 * theta1) / 2;
        double s2 = (pow(r2, 2) * 2 * theta2) / 2 - pow(r2, 2) * sin(2 * theta2) / 2;
        res = s1 + s2;
    }
    cout << fixed;
    cout.precision(3);
    cout << res;
    return 0;
}