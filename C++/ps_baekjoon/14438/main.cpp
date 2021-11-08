#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int n, m;

class SegTree
{
private:
    vector<int> tree;
    const vector<int>& data;
public:
    SegTree(const vector<int>& data) :data{data} { tree.resize(data.size() * 4); }

    int merge(int left, int right) { return min(left, right); }

    int build(int node = 1, int nodeLeft = 1, int nodeRight = n)
    {
        if (nodeLeft == nodeRight)
            return tree[node] = data[nodeLeft];
        int mid = (nodeLeft + nodeRight) / 2;
        int leftVal = build(node * 2, nodeLeft, mid);
        int rightVal = build(node * 2 + 1, mid + 1, nodeRight);
        return tree[node] = merge(leftVal, rightVal);
    }

    int query(int left, int right, int node = 1, int nodeLeft = 1, int nodeRight = n)
    {
        if (right < nodeLeft || nodeRight < left)
            return INF;
        if (left <= nodeLeft && nodeRight <= right)
            return tree[node];
        int mid = (nodeLeft + nodeRight) / 2;
        int leftVal = query(left, right, node * 2, nodeLeft, mid);
        int rightVal = query(left, right, node * 2 + 1, mid + 1, nodeRight);
        return merge(leftVal, rightVal);
    }

    int update(int index, int newVal, int node = 1, int nodeLeft = 1, int nodeRight = n)
    {
        if (index < nodeLeft || nodeRight < index)
            return tree[node];
        if (nodeLeft == nodeRight)
            return tree[node] = newVal;
        int mid = (nodeLeft + nodeRight) / 2;
        int leftVal = update(index, newVal, node * 2, nodeLeft, mid);
        int rightVal = update(index, newVal, node * 2 + 1, mid + 1, nodeRight);
        return tree[node] = merge(leftVal, rightVal);
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vector<int> data(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> data[i];
    SegTree st(data);
    st.build();
    cin >> m;
    while (m--)
    {
        int mode, i, j;
        cin >> mode >> i >> j;
        if (mode == 1)
            st.update(i, j);
        if (mode == 2)
            cout << st.query(i, j) << '\n';
    }
    return 0;
}