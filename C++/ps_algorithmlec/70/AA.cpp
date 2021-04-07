// cpp algorithm ps number 70

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int vertex, edge, index;
    cin >> vertex >> edge;
    vector<vector<int>> map(vertex + 1);
    queue<int> storage;
    auto trace = new bool[vertex + 1]{false};
    auto minimum = new int[vertex + 1]{0};
    for (int i = 0; i < edge;i++)
    {
        static int to, go;
        cin >> to >> go;
        map[to].push_back(go);
    }
    storage.push(1);
    trace[1] = true;
    while(!storage.empty())
    {
        static int temp;
        temp = storage.front();
        storage.pop();
        for (int i = 0; i < map[temp].size();i++)
        {
            if(!trace[map[temp][i]])
            {
                trace[map[temp][i]] = true;
                storage.push(map[temp][i]);
                minimum[map[temp][i]] = minimum[temp] + 1;
            }
        }
    }
    for (int i = 2; i <= vertex;i++)
        cout << i << " : " << minimum[i]<<'\n';

        return 0;
}