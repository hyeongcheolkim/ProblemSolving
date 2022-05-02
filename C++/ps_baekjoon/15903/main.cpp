#include <bits/stdc++.h>
using namespace std;

int n, m;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    while (n--)
    {
        long long num;
        cin >> num;
        pq.push(num);
    }
    while (m--)
    {
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();
        pq.push(first + second);
        pq.push(first + second);
    }
    long long sum = 0;
    while (!pq.empty())
    {
        sum += pq.top();
        pq.pop();
    }
    cout << sum;
    return 0;
}