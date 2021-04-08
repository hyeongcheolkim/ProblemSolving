// cpp algorithm ps number 75

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct offer
{
    int money;
    int day;
    bool operator<(const offer &temp)
    {
        return day > temp.day;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<offer> list(n);
    priority_queue<int> temp;
    int sum = 0;
    for (int i = 0; i < n; i++)
        cin >> list[i].money >> list[i].day;
    sort(list.begin(), list.end());
    int maxday = list.front().day;
    for (int i = maxday; i >= 1; i--)
    {
        while (!list.empty()&&list.front().day == i)
        {
            temp.push(list.front().money);
            list.erase(list.begin());
        }
        if (!temp.empty())
        {
            sum += temp.top();
            temp.pop();
        }
    }
    cout << sum;
    return 0;
}