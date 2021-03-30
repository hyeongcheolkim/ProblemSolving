// cpp algorithm ps number 48

#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

using namespace std;

int main()
{
    vector<vector<int>> arr(9, vector<int>(9));
    vector<int> avg(9);
    vector<int> near(9);

    for (int i = 0; i < 9; i++)
    {
        static int sum;
        sum = 0;
        for (int j = 0; j < 9; j++)
        {
            cin >> arr[i][j];
            sum += arr[i][j];
        }
        avg[i] = (int)floor((double)sum / 9.0 + 0.5);
    }

    for (int i = 0; i < 9; i++)
    {
        static int min;
        min = INT_MAX;
        for (int j = 0; j < 9; j++)
            if (abs(avg[i] - arr[i][j]) < min)
            {
                min = abs(avg[i] - arr[i][j]);
                near[i] = arr[i][j];
            }
    }
    for (int i = 0; i < 9; i++)
        cout << avg[i] << " " << near[i] << '\n';

    return 0;
}