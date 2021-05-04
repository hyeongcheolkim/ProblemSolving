//baekjoon ps 11286

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct number
{
    int num;
    number(int num)
    {
        this->num = num;
    }
    bool operator<(const number &obj) const
    {
        if (abs(this->num) == abs(obj.num))
            return this->num > obj.num;
        else
            return abs(this->num) > abs(obj.num);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<number> pq;
    int n;
    cin >> n;
    while (n--)
    {
        static int input;
        cin >> input;
        if (input == 0)
        {
            if (pq.empty())
                cout << 0 << '\n';
            else
            {
                cout << pq.top().num << '\n';
                pq.pop();
            }
        }
        else
            pq.push(input);
    }
    return 0;
}
