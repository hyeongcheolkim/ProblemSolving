// cpp algorithm ps number 47

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    int cnt = 0;
    cin >> n;
    vector<vector<int>> arr(n+2, vector<int>(n+2,0));
    for (int i = 1; i < n+1;i++)
        for (int j = 1; j < n+1;j++)
            cin >> arr[i][j];
    for (int i = 1; i < n+1;i++)
        for (int j = 1; j < n+1;j++)
            if(arr[i][j]>arr[i-1][j] && arr[i][j]>arr[i][j-1] && arr[i][j]>arr[i+1][j] && arr[i][j]>arr[i][j+1])
                cnt++;
    cout << cnt;

    return 0;
}

