// cpp algorithm ps number 22

#include <iostream>

using namespace std;

int main()
{
    int n, k;
    int i;
    int sum = 0;
    int max = -5000;
    cin >> n >> k;

    auto arr = new int[n];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        if (k - 1 == i)
        {
            max = sum;
            i++;
            break;
        }
    }
    for (int j = 0; i < n; i++, j++)
    {   
        cin >> arr[i];
        sum += (arr[i] - arr[j]);
        if (sum > max)
            max = sum;
    }
    cout << max;
    return 0;
}