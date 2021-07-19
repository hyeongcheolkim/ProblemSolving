//baekjoon ps 4803

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> uf;

int find(int num)
{
    if (uf[num] == num)
        return num;
    return uf[num] = find(uf[num]);
}

bool uni(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        uf[a] = b;
        return true;
    }
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int testcase = 1;; testcase++)
    {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        uf = move(vector<int>(n + 1));
        vector<int> not_tree;
        for (int i = 0; i <= n; i++)
            uf[i] = i;
        for (int i = 0; i < m; i++)
        {
            int from, to;
            cin >> from >> to;
            if (!uni(from, to))
                not_tree.push_back(from);
        }
        unordered_set<int> set;
        for (int i = 1; i <= n; i++)
            set.insert(find(i));
        for (const auto &e : not_tree)
            set.erase(find(e));
        int cnt = set.size();
        cout << "Case " << testcase << ": ";
        if (cnt >= 2)
            cout << "A forest of " << cnt << " trees." << '\n';
        else if (cnt == 1)
            cout << "There is one tree." << '\n';
        else if (cnt == 0)
            cout << "No trees." << '\n';
    }
    return 0;
}