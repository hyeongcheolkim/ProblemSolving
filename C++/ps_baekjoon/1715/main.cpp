//baekjoon ps 1715

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    unsigned long long res = 0;
    cin >> n;
    priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long>> pq;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        pq.push(input);
    }
    while (pq.size() >= 2)
    {
        auto first = pq.top();
        pq.pop();
        auto second = pq.top();
        pq.pop();
        res += first + second;
        pq.push(first + second);
    }
    cout << res;
    return 0;
}