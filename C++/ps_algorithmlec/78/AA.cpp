// cpp algorithm ps number 78

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct
{
    int to, go, cost;
} edge;

bool cmp(const edge &a, const edge &b)
{
    return a.cost <= b.cost;
}

int find(int num, vector<int> &setmap)
{
    if(num==setmap[num])
        return num;
    else
        return setmap[num]=find(setmap[num], setmap);
}

bool uni(int a, int b, vector<int> &setmap)
{
    a = find(a, setmap);
    b = find(b, setmap);
    if(a!=b)
    {
        setmap[a] = setmap[b];
        return true;
    }
    else
        return false;
}

int main()
{
    int v, e;
    int total = 0;
    cin >> v >> e;
    vector<edge> edges(e);
    vector<int> setmap(v + 1);
    for (int i = 1; i <= v; i++)
        setmap[i] = i;
    for (int i = 0; i < e; i++)
        cin >> edges[i].to >> edges[i].go >> edges[i].cost;
    sort(edges.begin(), edges.end(), cmp);
    for (int i = 0; i < e;i++)
    {
        if(uni(edges[i].to, edges[i].go, setmap))
            total += edges[i].cost;
    }
    cout << total;
    return 0;
}