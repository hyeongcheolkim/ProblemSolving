#include <bits/stdc++.h>
using namespace std;

string str, res;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> str;
    res.resize(str.size(), 'z');
    for (int cur1 = 0; cur1 < str.size(); ++cur1)
        for (int cur2 = cur1 + 1; cur2 < str.size(); ++cur2)
        {
            vector<string> arr(3);
            arr[0] = str.substr(0, cur1);
            arr[1] = str.substr(cur1, cur2 - cur1);
            arr[2] = str.substr(cur2);
            if (any_of(arr.begin(), arr.end(), [](string& e) {return e.empty(); }))
                continue;
            for_each(arr.begin(), arr.end(), [](string& e) {reverse(e.begin(), e.end()); });
            res = min(res, accumulate(arr.begin(), arr.end(), string(""), [](string a, string& b) {return a.append(b); }));
        }
    cout << res;
    return 0;
}