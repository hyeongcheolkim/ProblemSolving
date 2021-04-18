//baekjoon ps 15649

#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool check[10];
vector<int> arr;

void bfs(int level)
{
    if(level==m)
    {
        for(const auto &e:arr)
            cout << e << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n;i++)
    {
        if(!check[i])
        {
            check[i] = true;
            arr.push_back(i);
            bfs(level + 1);
            check[i] = false;
            arr.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    bfs(0);
    return 0;
}