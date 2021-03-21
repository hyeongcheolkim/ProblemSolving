// cpp algorithm ps number 25

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    auto arr = new int[n];
    auto score = new int[n]{0};

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        static int up = 1;
        for (int j = 0; j < n; j++)
            if (arr[j] > arr[i])
                up++;
        score[i] = up;
        up = 1;
    }
    for (int i = 0; i < n; i++)
        cout << score[i];
    return 0;
}