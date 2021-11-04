#include <bits/stdc++.h>
using namespace std;
using MinMax = pair<int, int>;

constexpr int INF = numeric_limits<int>::max() / 2;
int n, m;

class SegTree
{
private:
    vector<MinMax> tree;
    const vector<int>& data;
public:
    SegTree(const vector<int>& data) :data{data} { tree.resize(data.size() * 4); }

    MinMax merge(MinMax left, MinMax right)
    {
        return MinMax{min(left.first, right.first), max(left.second, right.second)};
    }

    MinMax build(int node, int nodeLeft, int nodeRight)
    {
        if (nodeLeft == nodeRight)
            return tree[node] = MinMax{data[nodeLeft], data[nodeLeft]};
        int mid = (nodeLeft + nodeRight) / 2;
        MinMax leftVal = build(node * 2, nodeLeft, mid);
        MinMax rightVal = build(node * 2 + 1, mid + 1, nodeRight);
        return tree[node] = merge(leftVal, rightVal);
    }

    MinMax query(int left, int right, int node, int nodeLeft, int nodeRight)
    {
        if (right < nodeLeft || nodeRight < left)
            return MinMax{INF, -INF};
        if (left <= nodeLeft && nodeRight <= right)
            return tree[node];
        int mid = (nodeLeft + nodeRight) / 2;
        MinMax leftVal = query(left, right, node * 2, nodeLeft, mid);
        MinMax rightVal = query(left, right, node * 2 + 1, mid + 1, nodeRight);
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
        auto res = st.query(a, b, 1, 1, n);
        cout << res.first << ' ' << res.second << '\n';
    }
    return 0;
}