#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int n, res = -INF;
string expression;
vector<int> val;
vector<char> oper;
vector<bool> oper_vst;

int calculate(char oper, int a, int b)
{
    switch (oper)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        default:
            return -1;
    }
}

int calculate_val()
{
    vector<int> tmp_val;
    vector<char> tmp_oper;
    int idx = 0;
    tmp_val.push_back(val[idx++]);
    for (int i = 0; i < oper.size(); ++i)
    {
        if (oper_vst[i])
        {
            int a = tmp_val.back();
            tmp_val.pop_back();
            int b = val[idx++];
            int res = calculate(oper[i], a, b);
            tmp_val.push_back(res);
        }
        else
        {
            tmp_val.push_back(val[idx++]);
            tmp_oper.push_back(oper[i]);
        }
    }
    stack<int> tmp;
    idx = 0;
    tmp.push(tmp_val[idx++]);
    for (const auto& e : tmp_oper)
    {
        int a = tmp.top();
        tmp.pop();
        int b = tmp_val[idx++];
        int res = calculate(e, a, b);
        tmp.push(res);
    }
    return tmp.top();
}

void dfs_oper(int level = 0)
{
    if (level >= oper.size())
    {
        int ret = calculate_val();
        res = max(res, ret);
        return;
    }
    oper_vst[level] = true;
    dfs_oper(level + 2);
    oper_vst[level] = false;
    dfs_oper(level + 1);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> expression;
    int tmp = 0;
    for (const auto& e : expression)
    {
        if (isdigit(e))
        {
            tmp *= 10;
            tmp += (e - '0');
        }
        if (ispunct(e))
        {
            val.push_back(tmp);
            oper.push_back(e);
            tmp = 0;
        }
    }
    val.push_back(tmp);
    oper_vst.resize(oper.size());
    dfs_oper();
    cout << res;
    return 0;
}