#include <bits/stdc++.h>
using namespace std;

constexpr int SIZE = 5;
array<int, SIZE> arr;

void print()
{
    for (const auto& e : arr)
        cout << e << ' ';
    cout << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < SIZE; ++i)
        cin >> arr[i];
    while (arr != array<int, SIZE>{1, 2, 3, 4, 5})
        for (int i = 0; i < SIZE - 1; ++i)
        {
            int idx = i;
            while (arr[idx] > arr[idx + 1])
            {
                swap(arr[idx], arr[idx + 1]);
                print();
            }
        }
    return 0;
}