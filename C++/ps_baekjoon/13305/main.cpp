//baekjoon ps 13305

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    unsigned long long index = 0;
    unsigned long long distance = 0;
    unsigned long long totalmoney = 0;
    cin >> n;
    vector<unsigned long long> road(n - 1);
    vector<unsigned long long> cost(n);
    for (int i = 0; i < n - 1; i++)
        cin >> road[i];
    for (int i = 0; i < n; i++)
        cin >> cost[i];
    for (int i = 0; i < n-1;i++)
    {
        distance += road[i];
        if(i == n-2 || cost[index]>cost[i+1])
        {
            totalmoney += cost[index] * distance;
            distance = 0;
            index = i + 1;
        }

    }
    cout << totalmoney;
    return 0;
}