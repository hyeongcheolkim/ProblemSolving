//baekjoon ps 11866

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    queue<int> q;
    vector<int> res;
    for (int i = 1; i <= n; i++)
        q.push(i);
    while (!q.empty())
    {
        static int index = 1;
        if (index % k != 0)
            q.push(q.front());
        else
            res.push_back(q.front());
        q.pop();
        index++;
    }
    cout << "<" << res[0];
    for (int i = 1; i < res.size();i++)
        cout << ", " << res[i];
    cout << ">";
    return 0;
}