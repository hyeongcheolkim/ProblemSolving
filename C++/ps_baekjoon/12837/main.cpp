#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, q;

class SegTree
{
private:
    vector<ll> tree;
    const vector<ll>& data;
public:
    SegTree(const vector<ll>& data) : data{data} { tree.resize(data.size() * 4); }

    ll merge(ll left, ll right) { return left + right; }

    ll build(int node = 1, int nodeLeft = 1, int nodeRight = n)
    {
        if (nodeLeft == nodeRight)
            return tree[node] = data[nodeLeft];
        int mid = (nodeLeft + nodeRight) / 2;
        ll leftVal = build(node * 2, nodeLeft, mid);
        ll rightVal = build(node * 2 + 1, mid + 1, nodeRight);
        return tree[node] = merge(leftVal, rightVal);
    }

    ll query(int left, int right, int node = 1, int nodeLeft = 1, int nodeRight = n)
    {
        if (right < nodeLeft || nodeRight < left)
            return 0;
        if (left <= nodeLeft && nodeRight <= right)
            return tree[node];
        int mid = (nodeLeft + nodeRight) / 2;
        ll leftVal = query(left, right, node * 2, nodeLeft, mid);
        ll rightVal = query(left, right, node * 2 + 1, mid + 1, nodeRight);
        return merge(leftVal, rightVal);
    }

    ll add(int index, ll newVal, int node = 1, int nodeLeft = 1, int nodeRight = n)
    {
        if (index < nodeLeft || nodeRight < index)
            return tree[node];
        if (nodeLeft == nodeRight)
            return tree[node] += newVal;
        int mid = (nodeLeft + nodeRight) / 2;
        ll leftVal = add(index, newVal, node * 2, nodeLeft, mid);
        ll rightVal = add(index, newVal, node * 2 + 1, mid + 1, nodeRight);
        return tree[node] = merge(leftVal, rightVal);
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    vector<ll> data(n + 1, 0);
    SegTree st(data);
    st.build();
    while (q--)
    {
        int option, i, j;
        cin >> option >> i >> j;
        if (option == 1)
            st.add(i, j);
        if (option == 2)
            cout << st.query(i, j) << '\n';
    }
    return 0;
}