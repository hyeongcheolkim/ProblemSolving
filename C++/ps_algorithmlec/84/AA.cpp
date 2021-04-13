// cpp algorithm ps number 84

#include <iostream>
#include <vector>

using namespace std;

typedef struct todo
{
    int time;
    int cost;
} todo;

int n;
int maxcost;

void dfs(int num, int sum, const vector<todo> &calender)
{
    if(num==n+1)
    {
        if(sum>maxcost)
            maxcost = sum;
        return;
    }
    if(num+calender[num].time<=n+1)
        dfs(num + calender[num].time, sum + calender[num].cost,calender);
    dfs(num + 1, sum, calender);
}

int main()
{
    cin >> n;
    vector<todo> calender(n + 1);
    vector<bool> check(n + 1, true);
    for (int i = 1; i <= n; i++)
        cin >> calender[i].time >> calender[i].cost;
    dfs(1,0,calender);
    cout << maxcost;
    return 0;
}