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

    int build(int node, int nodeLeft, int nodeRight)
    {
        if (nodeLeft == nodeRight)
            return tree[node] = data[nodeLeft];
        int mid = (nodeLeft + nodeRight) / 2;
        int leftVal = build(node * 2, nodeLeft, mid);
        int rightVal = build(node * 2 + 1, mid + 1, nodeRight);
        return tree[node] = merge(leftVal, rightVal);
    }

    int query(int left, int right, int node, int nodeLeft, int nodeRight)
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
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    vector<int> data(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> data[i];
    SegTree st(data);
    st.build(1, 1, n);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        cout << st.query(a, b, 1, 1, n) << '\n';
    }
    return 0;
}