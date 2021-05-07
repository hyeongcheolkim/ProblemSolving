//baekjoon ps 11758

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int res = 0;
    int arr1[4];
    int arr2[4];
    for (int i = 0; i < 3; i++)
        cin >> arr1[i] >> arr2[i];
    arr1[3] = arr1[0];
    arr2[3] = arr2[0];
    for (int i = 0; i < 3; i++)
        res += arr1[i] * arr2[i + 1];
    for (int i = 1; i < 4; i++)
        res -= arr1[i] * arr2[i - 1];
    if(res>0)
        cout << 1;
    else if(res<0)
        cout << -1;
    else
        cout << 0;
    return 0;
}