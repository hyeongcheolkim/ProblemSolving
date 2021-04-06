// cpp algorithm ps number 66

#include <iostream>
#include <vector>

using namespace std;
int cnt = 0;

void fnc(int n, const int &vertex, const int &edge, vector<int> *map)
{
    static auto trace = new bool[vertex+1]{false};
    trace[n] = true;
    if (n == vertex)
    {
        cnt++;
        return;
    }
    for (int i = 0; i < map[n].size(); i++)
        if (!trace[map[n][i]])
        {
            fnc(map[n][i], vertex, edge, map);
            trace[map[n][i]] = false;
        }
}

int main()
{
    int vertex, edge;
    cin >> vertex >> edge;
    auto map = new vector<int>[vertex+1];
    for (int i = 1; i <= edge; i++)
    {
        static int to, go;
        cin >> to >> go;
        map[to].push_back(go);
    }
    fnc(1, vertex, edge, map);
    cout << cnt;
    return 0;
}