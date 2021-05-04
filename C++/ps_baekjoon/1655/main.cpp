//baekjoon ps 1655

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    priority_queue<int, vector<int>, less<int>> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
    while (n--)
    {
        static int input;
        cin >> input;
        if (max_pq.empty())
            max_pq.push(input);
        else if (min_pq.empty())
            min_pq.push(input);
        else
        {
            if (max_pq.size() > min_pq.size())
                min_pq.push(input);
            else
                max_pq.push(input);
        }
        if (!max_pq.empty() && !min_pq.empty() && max_pq.top() > min_pq.top())
        {
            max_pq.push(min_pq.top());
            min_pq.pop();
            min_pq.push(max_pq.top());
            max_pq.pop();
        }
        cout << max_pq.top() <<'\n';
    }
    return 0;
}