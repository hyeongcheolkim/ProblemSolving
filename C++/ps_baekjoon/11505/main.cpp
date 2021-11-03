#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1'000'000'007;
int n, m, k;

class SegTree
{
private:
    vector<ll> tree;
    const vector<ll>& data;
public:
    SegTree(const vector<ll>& data) :data{data} { tree.resize(data.size() * 4); }
    
    ll merge(ll left, ll right) { return (left * right) % MOD; }
    
    ll build(int node, int nodeLeft, int nodeRight)
    {
        if (nodeLeft == nodeRight)
            return tree[node] = data[nodeLeft];
        int mid = (nodeLeft + nodeRight) / 2;
        ll leftVal = build(node * 2, nodeLeft, mid);
        ll rightVal = build(node * 2 + 1, mid + 1, nodeRight);
        return tree[node] = merge(leftVal, rightVal);
    }
    
    ll query(int left, int right, int node, int nodeLeft, int nodeRight)
    {
        if (left <= nodeLeft && nodeRight <= right)
            return tree[node];
        if (right < nodeLeft || nodeRight < left)
            return 1;
        int mid = (nodeLeft + nodeRight) / 2;
        ll leftVal = query(left, right, node * 2, nodeLeft, mid);
        ll rightVal = query(left, right, node * 2 + 1, mid + 1, nodeRight);
        return merge(leftVal, rightVal);
    }
    
    ll update(int index, ll newVal, int node, int nodeLeft, int nodeRight)
    {
        if (index < nodeLeft || nodeRight < index)
            return tree[node];
        if (nodeLeft == nodeRight)
            return tree[node] = newVal;
        int mid = (nodeLeft + nodeRight) / 2;
        ll leftVal = update(index, newVal, node * 2, nodeLeft, mid);
        ll rightVal = update(index, newVal, node * 2 + 1, mid + 1, nodeRight);
        return tree[node] = merge(leftVal, rightVal);
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    SegTree segtree(arr);
    segtree.build(1, 1, n);
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