// cpp algorithm ps number 64

#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;
void fnc(int n, const int &vertex, const int &edge, vector<vector<int>> map);
int main()
{
    int vertex, edge;

    cin >> vertex >> edge;
    vector<vector<int>> map(edge + 1, vector<int>(edge + 1, 0));

    for (int i = 1; i <= edge; i++)
    {
        static int to, go;
        cin >> to >> go;
        map[to][go] = 1;
    }
    fnc(1, vertex, edge, map);
    cout << cnt;
    return 0;
}

void fnc(int n, const int &vertex, const int &edge, vector<vector<int>> map)
{
    static bool *tf = new bool[vertex + 1]{false};
    tf[n] = true;
    if (n == vertex)
    {
        cnt++;
        return;
    }
    for (int i = 1; i <= edge; i++)
        if (map[n][i] && tf[i]==false)
        {
            fnc(i, vertex, edge, map);
            tf[i] = false;
        }
}