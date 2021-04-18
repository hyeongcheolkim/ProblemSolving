//baekjoon ps 14888

#include <iostream>
#include <limits>

using namespace std;

int n;
int num[20];
int operators[4];
int sum = 0;
int mini = 274000000;
int maxi = -274000000;

void bfs(int level)
{
    if (level == n - 1)
    {
        mini = min(mini, sum);
        maxi = max(maxi, sum);
        return;
    }
    int temp;
    temp = sum;
    for (int i = 0; i < 4; i++)
    {
        if (operators[i] > 0)
            switch (i)
            {
            case 0:
                operators[0]--;
                sum += num[level + 1];
                bfs(level + 1);
                sum = temp;
                operators[0]++;
                break;
            case 1:
                operators[1]--;
                sum -= num[level + 1];
                bfs(level + 1);
                sum = temp;
                operators[1]++;
                break;
            case 2:
                operators[2]--;
                sum *= num[level + 1];
                bfs(level + 1);
                sum = temp;
                operators[2]++;
                break;
            case 3:
                operators[3]--;
                sum /= num[level + 1];
                bfs(level + 1);
                sum = temp;
                operators[3]++;
                break;
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    for (int i = 0; i < 4; i++)
        cin >> operators[i];
    sum += num[0];
    bfs(0);
    cout << maxi << '\n';
    cout << mini << '\n';
    return 0;
}