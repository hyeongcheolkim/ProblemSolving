// cpp algorithm ps number 62

#include <iostream>

using namespace std;

int arr[10];
int temp[10];

void divide(int lt, int rt);

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    divide(0, n - 1);
    for (int i = 0; i < n;i++)
        cout << arr[i] << " ";
        return 0;
}

void divide(int lt, int rt)
{
    int mid;
    int p1, p2, p3;
    if (lt < rt)
    {
        mid = (lt + rt) / 2;
        divide(lt, mid);
        divide(mid + 1, rt);
        p1 = lt;
        p2 = mid + 1;
        p3 = lt;
        while (p1 <= mid && p2 <= rt)
        {
            if (arr[p1] < arr[p2])
                temp[p3++] = arr[p1++];
            else
                temp[p3++] = arr[p2++];
        }
        while (p1 <= mid)
            temp[p3++] = arr[p1++];
        while (p2 <= rt)
            temp[p3++] = arr[p2++];
        for (int i = 0; i <= rt; i++)
            arr[i] = temp[i];
    }
}