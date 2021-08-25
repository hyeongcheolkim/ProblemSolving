#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, sum = 0;
    cin >> n;
    vector<int> positive, negative;
    positive.reserve(n);
    negative.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        if (num > 0)
            positive.push_back(num);
        else
            negative.push_back(num);
    }
    sort(positive.begin(), positive.end());
    sort(negative.begin(), negative.end(), greater<int>());
    while (positive.size() >= 2)
    {
        int first = positive.back();
        positive.pop_back();
        int second = positive.back();
        positive.pop_back();
        if (first != 1 && second != 1)
            sum += first * second;
        else
            sum += first + second;
    }
    while (!positive.empty())
    {
        sum += positive.back();
        positive.pop_back();
    }
    while (negative.size() >= 2)
    {
        int first = negative.back();
        negative.pop_back();
        int second = negative.back();
        negative.pop_back();
        sum += first * second;
    }
    while (!negative.empty())
    {
        sum += negative.back();
        negative.pop_back();
    }
    cout << sum;
    return 0;
}