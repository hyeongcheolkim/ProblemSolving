//baekjoon ps 1197

#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int *arr;
int find(int num)
{
    if (arr[num] == num)
        return num;
    return arr[num] = find(arr[num]);
}
bool uni(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        arr[a] = b;
        return true;
    }
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int v, e, cnt = 0;
    long long res = 0;
    cin >> v >> e;
    vector<tuple<long long, int, int>> map;
    map.reserve(e);
    arr = new int[v + 1];
    for (int i = 1; i <= v; i++)
        arr[i] = i;
    while (e--)
    {
        static int v1, v2;
        static long long cost;
        cin >> v1 >> v2 >> cost;
        map.push_back({cost, v1, v2});
    }
    sort(map.begin(), map.end());
    for (const auto &e : map)
    {
        if (uni(get<1>(e), get<2>(e)))
        {
            res += get<0>(e);
            cnt++;
        }
        if (cnt == v - 1)
            break;
    }
    cout << res;
    delete[] arr;
    return 0;
}