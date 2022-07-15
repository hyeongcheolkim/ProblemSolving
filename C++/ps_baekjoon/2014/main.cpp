#include <bits/stdc++.h>
using namespace std;

int k, n, prev_prime;
vector<int> primes;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> k >> n;
    primes.reserve(n);
    while (k--)
    {
        int num;
        cin >> num;
        pq.push(num);
        primes.push_back(num);
    }
    while (n--)
    {
        while (prev_prime == pq.top())
            pq.pop();
        int mini = pq.top();
        pq.pop();
        for (const long long& p : primes)
        {
            if (long long mul = p * mini; mul > numeric_limits<int>::max())
                continue;
            pq.push(p * mini);
        }
        prev_prime = mini;
    }
    cout << prev_prime;
    return 0;
}