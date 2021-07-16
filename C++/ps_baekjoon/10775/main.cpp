//baekjoon ps 10775

#include <iostream>
#include <vector>

using namespace std;

vector<int> uf;

int find(int num)
{
    if (num == uf[num])
        return num;
    else
        return uf[num] = find(uf[num]);
};
void uni(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
        uf[a] = b;
};

int main()
{
    ios_base::sync_with_stdio(false);
    int G, P;
    int cnt = 0;
    cin >> G >> P;
    uf = move(vector<int>(G + 1));
    for (int i = 1; i <= G; i++)
        uf[i] = i;
    while (P--)
    {
        int g;
        cin >> g;
        int gate = find(g);
        if (gate != 0 && ++cnt)
            uni(g, gate - 1);
        else
            break;
    }
    cout << cnt;
    return 0;
}