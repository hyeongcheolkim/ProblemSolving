//baekjoon ps 1043

#include <iostream>
#include <vector>

using namespace std;

int *uf;

int find(int num)
{
    if (num == uf[num])
        return num;
    return uf[num] = find(uf[num]);
}

void uni(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
        uf[a] = b;
}

bool isuni(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
        return false;
    else
        return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, t;
    int res = 0;
    int know = 0;
    cin >> n >> m >> t;
    uf = new int[n + 1];
    for (int i = 0; i <= n; i++)
        uf[i] = i;
    vector<int> truth(t);
    for (int i = 0; i < t; i++)
        cin >> truth[i];
    if (!truth.empty())
    {
        know = truth.front();
        for (int i = 0; i < t; i++)
            uni(know, truth[i]);
    }
    vector<vector<int>> guest(m);
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        guest[i] = move(vector<int>(num));
        for (int j = 0; j < num; j++)
            cin >> guest[i][j];
        int first = guest[i].front();
        for (int j = 0; j < num; j++)
            uni(first, guest[i][j]);
    }
    for (int i = 0; i < guest.size(); i++)
        if (!isuni(know, guest[i].front()))
            res++;
    cout << res;
    delete[] uf;
    return 0;
}