//baekjoon ps 2470

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool cmp(const int &a, const int &b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    long long res1, res2, mini;
    long long psum, msum;
    cin >> n;
    vector<long long> p;
    vector<long long> m;
    p.reserve(n);
    m.reserve(n);
    for (int i = 0; i < n; i++)
    {
        static long long input;
        cin >> input;
        if (input > 0)
            p.push_back(input);
        else
            m.push_back(input);
    }
    sort(p.begin(), p.end());
    sort(m.begin(), m.end(), cmp);
    if (p.size() >= 2)
        psum = p[0] + p[1];
    else
        psum = LONG_MAX;
    if (m.size() >= 2)
        msum = -(m[0] + m[1]);
    else
        msum = LONG_MAX;
    if (psum < msum && p.size() >= 2)
    {
        mini = abs(p[0] + p[1]);
        res1 = p[0];
        res2 = p[1];
    }
    else if (psum >= msum && m.size() >= 2)
    {
        mini = abs(m[0] + m[1]);
        res1 = m[1];
        res2 = m[0];
    }
    int pc = 0, mc = 0;
    while (pc < p.size() && mc < m.size())
    {
        if (abs(p[pc] + m[mc]) < mini)
        {
            mini = abs(p[pc] + m[mc]);
            res1 = m[mc];
            res2 = p[pc];
        }
        if (p[pc] + m[mc] < 0)
            pc++;
        else if (p[pc] + m[mc] > 0)
            mc++;
        else
            break;
    }
    cout << res1 << " " << res2;
    return 0;
}