#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
int root;

vector<int> trace(int node)
{
    vector<int> ret;
    while (node != root)
    {
        ret.push_back(node);
        node = parent[node];
    }
    ret.push_back(root);
    reverse(ret.begin(), ret.end());
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, n1, n2;
        cin >> n;
        parent.assign(n + 1, 0);
        while (--n)
        {
            int a, b;
            cin >> a >> b;
            parent[b] = a;
        }
        cin >> n1 >> n2;
        for (int i = 1; i < parent.size(); ++i)
            if (parent[i] == 0)
            {
                root = i;
                break;
            }
        auto t1 = trace(n1);
        auto t2 = trace(n2);
        int idx = 0;
        while (idx < t1.size() && idx < t2.size() && t1[idx] == t2[idx])
            ++idx;
        cout << t1[--idx] << '\n';
    }
    return 0;
}