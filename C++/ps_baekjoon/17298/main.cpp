//baekjoon ps 17298

#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <utility>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    stack<pair<int,int>> s;
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++)
    {
        static int input;
        cin >> input;
        if (s.empty())
            s.push({input,i});
        else if (s.top().first >= input)
            s.push({input,i});
        else
        {
            while (!s.empty() && s.top().first < input)
            {
                res[s.top().second] = input;
                s.pop();
            }
            s.push({input,i});
        }
    }
    for (const auto &e : res)
        cout << e << " ";
    return 0;
}