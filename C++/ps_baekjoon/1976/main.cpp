//baekjoon ps 1717

#include <iostream>

using namespace std;

int n, m;
int *arr;

int find(const int &a)
{
    if (a == arr[a])
        return a;
    return arr[a] = find(arr[a]);
}

void uni(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
        arr[a] = b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int input, code;
    bool flag = true;
    cin >> n >> m;
    arr = new int[n + 1];
    for (int i = 1; i <= n; i++)
        arr[i] = i;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> input;
            if (i <= j && input)
                uni(i, j);
        }
    if (m == 0)
    {
        cout << "YES";
        return 0;
    }
    cin >> input;
    code = find(input);
    for (int i = 1; i < m; i++)
    {
        cin >> input;
        if (code != find(input))
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "YES";
    else
        cout << "NO";
    delete[] arr;
    return 0;
}