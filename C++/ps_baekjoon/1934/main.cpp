//baekjoon ps 1934

#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

pair<int, int> uclid(pair<int, int> input)
{
    int temp;
    if ((temp = input.first % input.second) == 0)
        return {input};
    return uclid({input.second, temp});
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    pair<int, int> res;
    cin >> T;
    while (T--)
    {
        static int a, b;
        cin >> a >> b;
        res = uclid({max(a, b), min(a, b)});
        cout << a*b/res.second << '\n';
    }
    return 0;
}