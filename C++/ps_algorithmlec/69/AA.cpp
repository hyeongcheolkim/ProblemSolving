// cpp algorithm ps number 69

#include <iostream>
#include <vector>

using namespace std;

int Q[100], front = -1, back = -1, ch[10];
vector<int> map[10];

int main()
{
    int a, b, x;
    for (int i = 1; i <= 6;i++)
    {
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }
    Q[++back] = 1;
    ch[1] = 1;
    while(front<back)
    {
        x = Q[++front];
        cout << x;
        for (int i = 0; i < map[x].size();i++)
        {
            if(ch[map[x][i]]==0)
            {
                ch[map[x][i]] = 1;
                Q[++back] = map[x][i];
            }
        }
    }
    return 0;
}