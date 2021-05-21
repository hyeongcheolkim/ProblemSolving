//baekjoon ps 9019

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        queue<pair<unsigned short, string>> q;
        vector<bool> check(10000, false);
        q.push({a, ""});
        check[a] = true;
        while (!q.empty())
        {
            int num = q.front().first;
            if (num == b)
                break;
            string res = q.front().second;

            num = q.front().first;
            num *= 2;
            num = num % 10000;
            if (!check[num])
            {
                check[num] = true;
                q.push({num, res + "D"});
            }

            num = q.front().first;
            num -= 1;
            num = num == -1 ? 9999 : num;
            if (!check[num])
            {
                check[num] = true;
                q.push({num, res + "S"});
            }

            num = q.front().first;
            num = (num % 1000) * 10 + num / 1000;
            if (!check[num])
            {
                check[num] = true;
                q.push({num, res + "L"});
            }

            num = q.front().first;
            num = (num % 10) * 1000 + num / 10;
            if (!check[num])
            {
                check[num] = true;
                q.push({num, res + "R"});
            }
            q.pop();
        }
        cout << q.front().second << '\n';
    }
    return 0;
}
