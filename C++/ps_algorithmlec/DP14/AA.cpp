// cpp algorithm ps number DP14

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int vertex, edge;
    int cnt = 1;
    cin >> vertex >> edge;
    vector<vector<int>> map(vertex+1);
    vector<int> degree(vertex + 1, 0);
    queue<int> Q;
    for (int i = 0; i < edge;i++)
    {
        static int to, go;
        cin >> to >> go;
        map[to].push_back(go);
        degree[go]++;
        cnt++;
    }

    while(cnt)
    {
        if(Q.empty())
        for (int i = 1; i <= vertex;i++)
            if(degree[i]==0)
              {
                  Q.push(i);
                  degree[i]--;
              }  
                  
        for (int i = 0; i < map[Q.front()].size();i++)
        {
            degree[map[Q.front()][i]]--;
            cnt--;
        }
        cout << Q.front()<< ' ';
        Q.pop();
    }

    return 0;
}