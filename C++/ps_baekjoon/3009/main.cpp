//baekjoon 3009 ps

#include <iostream>
#include <utility>
#include <array>
using namespace std;

int main()
{
    typedef pair<double, double> dot;
    array<dot, 3> arr;
    dot center;

    for (int i = 0; i < 3; i++)
        cin >> arr[i].first >> arr[i].second;

    for (int i = 0; i < 3; i++)
    {
        int flag = 0;
        for (int j = i + 1; j < 3; j++)
            if (arr[i].first != arr[j].first && arr[i].second != arr[j].second)
            {
                center.first = (arr[i].first + arr[j].first) / 2;
                center.second = (arr[i].second + arr[j].second) / 2;

                for (int n = 0; n < 3; n++)
                    if (n != i && n != j)
                    {
                        cout << center.first * 2 - arr[n].first << " " << center.second * 2 - arr[n].second;
                        flag = 1;
                        break;
                    }
                break;
            }
        if (flag == 1)
            break;
    }
    return 0;
}
