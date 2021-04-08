// cpp algorithm ps number 72

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    queue<int> arr;
    for (int i = 1; i <= n; i++)
        arr.push(i);
    for (int i = 1; arr.size() != 1; i++)
        if (i % k != 0)
        {
            static int temp;
            temp = arr.front();
            arr.pop();
            arr.push(temp);
        }
        else
            arr.pop();
    cout << arr.front();
    return 0;
}