//baekjoon ps 17386

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    double x1, y1, x2, y2, x3, y3, x4, y4;
    double delta, dx1, dx2, dy1, dy2;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x3 >> y4;
    dx1 = (x2 - x1);
    dy1 = (y2 - y1);
    dx2 = (x4 - x3);
    dy2 = (y4 - y3);
    return 0;
}