#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;
using square = pair<pos, pos>;

int n;
vector<int> uf;
vector<square> sq;

int find(int num)
{
    if (uf[num] == num)
        return num;
    return uf[num] = find(uf[num]);
}

void uni(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
        uf[b] = a;
}

bool is_overlap(square s1, square s2)
{
    const auto& [s1_row1, s1_col1] = s1.first;
    const auto& [s1_row2, s1_col2] = s1.second;
    const auto& [s2_row1, s2_col1] = s2.first;
    const auto& [s2_row2, s2_col2] = s2.second;

    if (s2_col2 > s1_col2 && s1_row2 < s2_row2 && s1_col1 > s2_col1 && s2_row1 < s1_row1)
        return false;
    if (s1_col2 > s2_col2 && s2_row2 < s1_row2 && s2_col1 > s1_col1 && s2_row1 > s1_row1)
        return false;
    if (s2_col1 > s1_col2 || s2_row1 > s1_row2 || s1_col1 > s2_col2 || s2_row2 < s1_row1)
        return false;
    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    sq.reserve(n + 1);
    sq.emplace_back(pos{0, 0}, pos{0, 0});
    uf.resize(n + 1);
    iota(uf.begin(), uf.end(), 0);
    for (int i = 0; i < n; ++i)
    {
        int row1, col1, row2, col2;
        cin >> row1 >> col1 >> row2 >> col2;
        sq.emplace_back(pos{row1, col1}, pos{row2, col2});
    }
    for (int i = 0; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (is_overlap(sq[i], sq[j]))
                uni(i, j);
    set<int> s;
    for (int i = 0; i <= n; ++i)
        s.insert(find(uf[i]));
    cout << s.size() - 1;
    return 0;
}