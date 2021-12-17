#include <bits/stdc++.h>
using namespace std;
using datum = pair<int, int>;

constexpr int INF = numeric_limits<int>::max() / 2;
int n, m;

class SegTree
{
private:
    vector<datum> tree;
    const vector<datum>& data;
public:
    SegTree(const vector<datum>& data) : data{data} { tree.resize(data.size() * 4); }

    datum merge(datum left, datum right) { return min(left, right); }

    datum build(int node = 1, int nodeLeft = 1, int nodeRight = n)
    {
        if (nodeLeft == nodeRight)
            return tree[node] = data[nodeLeft];
        int mid = (nodeLeft + nodeRight) / 2;
        datum leftVal = build(node * 2, nodeLeft, mid);
        datum rightVal = build(node * 2 + 1, mid + 1, nodeRight);
        return tree[node] = merge(leftVal, rightVal);
    }

    datum query(int left, int right, int node = 1, int nodeLeft = 1, int nodeRight = n)
    {
        if (right < nodeLeft || nodeRight < left)
            return datum{INF, INF};
        if (left <= nodeLeft && nodeRight <= right)
            return tree[node];
        int mid = (nodeLeft + nodeRight) / 2;
        datum leftVal = query(left, right, node * 2, nodeLeft, mid);
        datum rightVal = query(left, right, node * 2 + 1, mid + 1, nodeRight);
        return merge(leftVal, rightVal);
    }

    datum update(int index, int newVal, int node = 1, int nodeLeft = 1, int nodeRight = n)
    {
        if (index < nodeLeft || nodeRight < index)
            return tree[node];
        if (nodeLeft == nodeRight)
            return tree[node] = datum{newVal, nodeLeft};
        int mid = (nodeLeft + nodeRight) / 2;
        datum leftVal = update(index, newVal, node * 2, nodeLeft, mid);
        datum rightVal = update(index, newVal, node * 2 + 1, mid + 1, nodeRight);
        return tree[node] = merge(leftVal, rightVal);
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vector<datum> data(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> data[i].first;
        data[i].second = i;
    }
    SegTree st(data);
    st.build();
    cin >> m;
    while (m--)
    {
        int mode, a, b;
        cin >> mode >> a >> b;
        if (mode == 1)
            st.update(a, b);
        if (mode == 2)
            cout << st.query(a, b).second << '\n';
    }
    return 0;
}