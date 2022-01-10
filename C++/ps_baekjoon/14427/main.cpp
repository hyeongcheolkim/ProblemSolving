#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int n, m, oper;

class SegTree
{
private:
    vector<int> tree;
    vector<int>& data;
public:
    SegTree(vector<int>& data) : data{data} { tree.resize(this->data.size() * 4); }
    int merge(int left, int right) { return data[left] <= data[right] ? left : right; }
    int build(int node = 1, int nodeLeft = 1, int nodeRight = n)
    {
        if (nodeLeft == nodeRight)
            return tree[node] = nodeLeft;
        int mid = (nodeLeft + nodeRight) / 2;
        int leftVal = build(node * 2, nodeLeft, mid);
        int rightVal = build(node * 2 + 1, mid + 1, nodeRight);
        return tree[node] = merge(leftVal, rightVal);
    }
    int query(int left = 1, int right = n, int node = 1, int nodeLeft = 1, int nodeRight = n)
    {
        if (right < nodeLeft || nodeRight < left)
            return 0;
        if (left <= nodeLeft && nodeRight <= right)
            return tree[node];
        int mid = (nodeLeft + nodeRight) / 2;
        int leftVal = query(left, right, node * 2, nodeLeft, mid);
        int rightVal = query(left, right, node * 2 + 1, mid + 1, nodeRight);
        return merge(leftVal, rightVal);
    }
    int update(int idx, int newVal, int node = 1, int nodeLeft = 1, int nodeRight = n)
    {
        if (idx < nodeLeft || nodeRight < idx)
            return tree[node];
        if (nodeLeft == nodeRight)
        {
            data[idx] = newVal;
            return tree[node] = nodeLeft;
        }
        int mid = (nodeLeft + nodeRight) / 2;
        int leftVal = update(idx, newVal, node * 2, nodeLeft, mid);
        int rightVal = update(idx, newVal, node * 2 + 1, mid + 1, nodeRight);
        return tree[node] = merge(leftVal, rightVal);
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    arr[0] = INF;
    SegTree st(arr);
    st.build();
    cin >> m;
    while (m--)
    {
        cin >> oper;
        switch (int i, v; oper)
        {
            case 1:
                cin >> i >> v;
                st.update(i, v);
                break;
            case 2:
                cout << st.query() << '\n';
                break;
            default:
                break;
        }
    }
    return 0;
}