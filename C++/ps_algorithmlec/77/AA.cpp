// cpp algorithm ps number 77

#include <iostream>
#include <vector>

using namespace std;

int find(int num, vector<int> &arr)
{
    if (num == arr[num])
        return num;
    else
        return find(arr[num], arr);
}

void uni(int a, int b, vector<int> &arr)
{
    a = find(a, arr);
    b = find(b, arr);
    if(a!=b)
        arr[a] = b;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        arr[i] = i;
    for (int i = 0; i < m; i++)
    {
        static int a, b;
        cin >> a >> b;
        uni(a, b, arr);
    }
    int p1, p2;
    cin >> p1 >> p2;
    if(find(p1,arr)==find(p2,arr))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}