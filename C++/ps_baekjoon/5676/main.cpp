#include <bits/stdc++.h>
using namespace std;

int n, k;

class SegTree
{
private:
    vector<int> tree;
    const vector<int>& data;
public:
    SegTree(const vector<int>& data) :data{data} { tree.resize(data.size() * 4); }

    int merge(int left, int right)
    {
        int p = left * right;
        if (p > 0)
            return 1;
        if (p == 0)
            return 0;
        return -1;
    }

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
            return 1;
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
    while (cin >> n >> k)
    {
        vector<int> data(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> data[i];
        SegTree st(data);
        st.build();
        while (k--)
        {
            char order;
            int i, v;
            cin >> order >> i >> v;
            if (order == 'C')
                st.update(i, v);
            if (order == 'P')
            {
                auto res = st.query(i, v);
                if (res > 0)
                    cout << '+';
                else if (res == 0)
                    cout << '0';
                else if (res < 0)
                    cout << '-';
            }
        }
        cout << '\n';
    }
    return 0;
}