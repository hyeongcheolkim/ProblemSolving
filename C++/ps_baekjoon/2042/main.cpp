#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, k;

class SegTree
{
private:
    int size;
    vector<ll> tree;
    const vector<ll>& arr;
public:
    SegTree(const vector<ll>& data, const int& size) : arr{data}
    {
        this->size = size;
        tree.resize(data.size() * 4);
        this->build(1, 1, size);
    }

    ll merge(ll left, ll right) { return left + right; }

    ll build(int node, int nodeLeft, int nodeRight)
    {
        if (nodeLeft == nodeRight)
            return tree[node] = arr[nodeLeft];
        int mid = (nodeLeft + nodeRight) / 2;
        ll leftVal = build(node * 2, nodeLeft, mid);
        ll rightVal = build(node * 2 + 1, mid + 1, nodeRight);
        return tree[node] = merge(leftVal, rightVal);
    }

    ll query(int left, int right, int node, int nodeLeft, int nodeRight)
    {
        if (right < nodeLeft || nodeRight < left)
            return 0;
        if (left <= nodeLeft && nodeRight <= right)
            return tree[node];
        int mid = (nodeLeft + nodeRight) / 2;
        return merge(query(left, right, node * 2, nodeLeft, mid),
            query(left, right, node * 2 + 1, mid + 1, nodeRight));
    }

    ll update(int index, ll newValue, int node, int nodeLeft, int nodeRight)
    {
        if (index < nodeLeft || nodeRight < index)
            return tree[node];
        if (nodeLeft == nodeRight)
            return tree[node] = newValue;
        int mid = (nodeLeft + nodeRight) / 2;
        ll leftVal = update(index, newValue, node * 2, nodeLeft, mid);
        ll rightVal = update(index, newValue, node * 2 + 1, mid + 1, nodeRight);
        return tree[node] = merge(leftVal, rightVal);
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    vector<ll> data(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> data[i];
    SegTree segtree(data, n);
    for (int i = 0; i < m + k; ++i)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            segtree.update(b, c, 1, 1, n);
        if (a == 2)
            cout << segtree.query(b, c, 1, 1, n) << '\n';
    }
    return 0;
}