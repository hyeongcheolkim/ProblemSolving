// cpp algorithm ps number 63

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int vertex, edge;
    cin >> vertex >> edge;
    vector<vector<int>> map(vertex+1, vector<int>(vertex+1));
    for (int i = 1; i <= edge;i++)
    {
        static int to, go, add;
        cin >> to >> go >> add;
        map[to][go] = add;
    }
    for (int i = 1; i <= vertex;i++)
    {
        for (int j = 1; j <= vertex;j++)
            cout << map[i][j] << " ";
        cout << '\n';
    }
        return 0;
}