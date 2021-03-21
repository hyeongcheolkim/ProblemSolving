//baekjoon 1002 ps

#include <iostream>
#include <utility>
#include <cmath>
using namespace std;

int main()
{
    typedef pair<double, double> dot;

    dot dot1, dot2;
    double r1, r2;
    double distance;
    int n;
    cin >> n;

    while (n > 0)
    {
        cin >> dot1.first >> dot1.second >> r1 >> dot2.first >> dot2.second >> r2;

        distance = sqrt(pow(dot1.first - dot2.first, 2) + pow(dot1.second - dot2.second, 2));


        if (distance > r1 + r2)
            cout << "0" << endl;
        else if (distance == r1 + r2)
            cout << "1" << endl;
        else if (distance < r1 + r2)
            if(distance> abs(r1-r2))
                cout << "2" << endl;
            else if (distance == abs(r1-r2))
                if(r1==r2)
                    cout << "-1" << endl;
                else
                    cout << "1" << endl;
            else if(distance<abs(r1-r2))
                cout << "0" << endl;
            
        n--;
    }

    return 0;
}