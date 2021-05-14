//baekjoon ps 20040

#include <iostream>
#include <utility>

using namespace std;

int n, m;
int *arr;
bool flag = false;
int find(const int &a)
{
    if (a == arr[a])
        return a;
    return arr[a] = find(arr[a]);
}

pair<int, int> uni(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
        arr[a] = b;
    return {a, b};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = i;
    while (m--)
    {
        static int p1, p2, cnt = 1;
        static pair<int, int> temp;
        cin >> p1 >> p2;
        temp = uni(p1, p2);
        if (temp.first == temp.second)
        {
            cout << cnt;
            return 0;
        }
        cnt++;
    }
    cout << 0;
    delete[] arr;
    return 0;
}