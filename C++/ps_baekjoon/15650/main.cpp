//baekjoon ps 15650

#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;
bool check[10];

void bfs(int level, int num)
{
    if(level==m)
    {
        for (const auto &e:arr)
            cout << e << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1+num; i<= n; i++)
    {
        if(!check[i])
        {
            check[i] = true;
            arr.push_back(i);
            bfs(level + 1, i);
            check[i] = false;
            arr.pop_back();
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    bfs(0,0);
    return 0;
}