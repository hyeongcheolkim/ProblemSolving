//baekjoon ps 11066

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    using ull = unsigned long long;
    int t;
    cin >> t;
    while (t--)
    {
        priority_queue<ull, vector<ull>, greater<ull>> pq;
        int k;
        ull res = 0;
        cin >> k;
        while (k--)
        {
            int num;
            cin >> num;
            pq.push(num);
        }
        while (pq.size() > 1)
        {
            ull first = pq.top();
            pq.pop();
            ull second = pq.top();
            pq.pop();
            res += first + second;
            pq.push(first + second);
        }
        cout << res << '\n';
    }
    return 0;
}