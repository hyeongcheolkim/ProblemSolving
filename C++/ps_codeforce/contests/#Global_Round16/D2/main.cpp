#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 1, mxM = 3e2;

struct person
{
    int sight;
    int idx;
    person() {}
    person(const int &sight, const int &idx)
    {
        this->sight = sight;
        this->idx = idx;
    }
    bool operator<(const person &obj) const
    {
        if (this->sight != obj.sight)
            return this->sight < obj.sight;
        else
            return this->idx > obj.idx;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, res = 0;
        cin >> n >> m;
        int ea = n * m;
        vector<person> a(ea + 1);
        vector<int> s(ea + 1);
        vector<vector<bool>> check(n + 1, vector<bool>(m + 1));
        for (int i = 1; i <= ea; ++i)
        {
            cin >> a[i].sight;
            a[i].idx = i;
        }
        sort(a.begin() + 1, a.end());
        for (int i = 1; i <= ea; ++i)
        {
            int index = a[i].idx;
            s[index] = i;
        }
        for (int i = 1; i <= ea; ++i)
        {
            int num = s[i];
            int row = (num - 1) / m + 1;
            int col = (num - 1) % m + 1;
            if (col == 0)
                col = m;
            for (int i = 1; i < col; ++i)
                if (check[row][i])
                    ++res;
            check[row][col] = true;
        }
        cout << res << '\n';
    }
    return 0;
}