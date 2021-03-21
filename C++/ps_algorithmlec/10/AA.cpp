// cpp algorithm ps number 10

#include <iostream>

using namespace std;

int digit_sum(int x);

int main()
{
    int n;
    cin >> n;
    int max = 0;
    int max_num = 0;
    auto arr = new unsigned int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        static int sum = 0;
        sum = digit_sum(arr[i]);
        if (sum > max)
        {
            max = move(sum);
            max_num = arr[i];
        }
        else if (sum == max)
            if (arr[i] > max_num)
                max_num = arr[i];
    }

    cout << max_num;

    return 0;
}

int digit_sum(int x)
{
    int sum = 0;
    for (; x != 0; x /= 10)
        sum += x % 10;
    return sum;
}