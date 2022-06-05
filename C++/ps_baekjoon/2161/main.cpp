#include <bits/stdc++.h>
using namespace std;

int n;
deque<int> cards;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    cards.resize(n);
    iota(cards.begin(), cards.end(), 1);
    while (cards.size() > 1)
    {
        cout << cards.front() << ' ';
        cards.pop_front();
        rotate(cards.begin(), cards.begin() + 1, cards.end());
    }
    cout << cards.front();
    return 0;
}