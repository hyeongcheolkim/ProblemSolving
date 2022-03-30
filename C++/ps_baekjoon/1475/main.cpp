#include <bits/stdc++.h>
using namespace std;

array<int, 9 + 1> number;
string room;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    number.fill(0);
    cin >> room;
    for (const auto& e : room)
        ++number[e - '0'];
    number[6] = number[9] = ceil((number[6] + number[9]) / 2.0);
    cout << *max_element(number.begin(), number.end());
    return 0;
}