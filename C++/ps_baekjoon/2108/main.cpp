//baekjoon 2108 ps

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <array>
#include <cmath>

using namespace std;

int main()
{
    //input n
    int n;
    scanf("%d", &n);

    // value declare for calculating average, max, min
    int total = 0;
    int max = -4001;
    int min = 4001;

    vector<int> arr;
    arr.assign(n, 0);
    array<int, 8001> cmp{0};

    //input number. calculate max min total
    for (int i = 0; i < n; i++)
    {
        static int num = 0;
        scanf("%d", &num);
        total += num;
        if (num > max)
            max = num;
        if (num < min)
            min = num;
        arr[i] = num;
        cmp[num + 4000]++;
    }

    //sorting arr
    sort(arr.begin(), arr.end());

    //calculate mode value
    pair<int, int> mode1{0, 0};
    pair<int, int> mode2{0, 0};
    for (int i = 8000; i >= 0; i--)
    {
        static int max = -1;
        if (cmp[i] >= max)
        {
            max = cmp[i];
            swap(mode1, mode2);
            mode1.first = cmp[i];
            mode1.second = i - 4000;
        }
    }

    printf("%d\n%d\n%d\n%d", (int)round((double)total / (double)n), arr[n / 2], mode1.first == mode2.first ? mode2.second : mode1.second, max - min);

    return 0;
}