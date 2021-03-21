// cpp algorithm ps number 18

#include <iostream>

using namespace std;

int main()
{
    int n, m;
    int time = 0;
    int time_max = 0;
    cin >> n >> m;
    while (n--)
    {
        static int hz = 0;
        cin >> hz;
        if (hz > m)
        {
            time++;
            if (time >= time_max)
                time_max = time;
        }
            
        else
        {
            if (time >= time_max)
                time_max = time;
            time = 0;
        }
    }
    if (time_max == 0)
        cout << "-1";
    else
        cout << time_max;
    return 0;
}