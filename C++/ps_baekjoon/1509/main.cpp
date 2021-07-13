//baekjoon ps 1509

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int cnt = 0;
    string input;
    cin >> input;
    int len = input.length();
    input = move(string(" ").append(input));
    vector<vector<bool>> palindrome(len + 1, vector<bool>(len + 1, false));
    vector<int> dp(len + 1, 0);
    function<void(int, int)> recursion = [&](int lt, int rt)
    {
        if (lt == 0 || rt == len + 1)
            return;
        if (input[lt] == input[rt])
        {
            palindrome[lt][rt] = true;
            recursion(lt - 1, rt + 1);
        }
        else
        {
            palindrome[lt][rt] = false;
            return;
        }
    };
    for (int i = 1; i <= len; i++)
        recursion(i, i);
    for (int i = 1; i <= len - 1; i++)
        recursion(i, i + 1);
    for (int rt = 1; rt <= len; rt++)
    {
        dp[rt] = numeric_limits<int>::max();
        for (int lt = 1; lt <= rt; lt++)
            if (palindrome[lt][rt])
                dp[rt] = min(dp[rt], dp[lt - 1] + 1);
    }
    cout << dp[len];
    return 0;
}