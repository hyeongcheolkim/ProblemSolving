#include <bits/stdc++.h>
using namespace std;
using Long = long long;

constexpr int INF = numeric_limits<int>::max() / 2;
int n;

class SegTree
{
private:
    vector<int> tree;
    const vector<int>& data;
public:
    SegTree(const vector<int>& data) : data{data} { tree.resize(this->data.size() * 4); }
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
    int query(int left, int right, int node = 1, int nodeLeft = 1, int nodeRight = n)
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
    Long get_max(int left = 1, int right = n)
    {
        if (left > right)
            return 0;
        int idx = query(left, right);
        Long ret = (right - left + 1) * data[idx];
        if (left < idx)
            ret = max(ret, get_max(left, idx - 1));
        if (idx < right)
            ret = max(ret, get_max(idx + 1, right));
        return ret;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vector<int> height(n + 1);
    height[0] = INF;
    for (int i = 1; i <= n; ++i)
        cin >> height[i];
    SegTree st(height);
    st.build();
    cout << st.get_max();
    return 0;
}