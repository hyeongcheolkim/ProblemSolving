//baekjoon ps 12015

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> res;
    res.reserve(n + 1);
    res.push_back(0);
    while (n--)
    {
        static int input;
        cin >> input;
        if (res.back() < input)
            res.push_back(input);
        else
            *lower_bound(res.begin(), res.end(), input) = input;
    }
    cout << res.size()-1;
    return 0;
}