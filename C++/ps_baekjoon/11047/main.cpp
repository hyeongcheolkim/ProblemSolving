//baekjoon ps 11047

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, k;
    int cnt = 0;
    cin >> n >> k;
    vector<int> coin(n);
    for (int i = 0; i < n; i++)
        cin >> coin[i];
    for (int i = n-1; i >=0;i--)
    {
        if(k==0)
            break;
        while(k>=coin[i])
        {
            k -= coin[i];
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}