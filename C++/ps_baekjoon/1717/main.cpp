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
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    arr = new int[n + 1];
    for (int i = 1; i <= n; i++)
        arr[i] = i;
    while (m--)
    {
        static int c, a, b;
        cin >> c >> a >> b;
        switch (c)
        {
        case 0:
            uni(a, b);
            break;
        case 1:
            if (find(a) == find(b))
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
            break;
        default:
            break;
        }
    }
    delete[] arr;
    return 0;
}