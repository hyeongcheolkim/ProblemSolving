//baekjoon ps 9663

#include <iostream>

using namespace std;

int n;
int cnt = 0;
int map[20];

void bfs(int queen)
{
    
    if (queen == n)
    {
        cnt++;
        return;
    }
    for (int column = 0; column < n; column++)
    {
        static bool flag;
        flag = true;
        for (int index = 0; index < queen; index++)
        {
            if (map[index] == column || abs(column - map[index]) == abs(queen - index))
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            map[queen] = column;
            bfs(queen + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    bfs(0);
    cout << cnt;
    return 0;
}