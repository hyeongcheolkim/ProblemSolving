//baekjoon ps 1922

#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
using edge = tuple<int, int, int>;

int n, m;
vector<int> tree;

int find(int n)
{
    if (tree[n] == n)
        return n;
    else
        return tree[n] = find(tree[n]);
}

bool uni(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        tree[a] = b;
        return true;
    }
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int res = 0;
    int num = 0;
    cin >> n >> m;
    tree = vector<int>(n + 1);
    for (int i = 1; i <= n; i++)
        tree[i] = i;
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({c, a, b});
    }
    while (!pq.empty())
    {
        if(num == n)
            break;
        int cost = get<0>(pq.top());
        int to = get<1>(pq.top());
        int go = get<2>(pq.top());
        pq.pop();
        if (uni(to, go))
        {
            res += cost;
            num++;
        }
    }
    cout << res;
    return 0;
}