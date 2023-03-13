#include <bits/stdc++.h>
using namespace std;

int s, p, res;
string pw;
vector<char> dna{'A', 'C', 'G', 'T'};
unordered_map<char, int> cnt, sub_cnt;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> s >> p >> pw;
    for (const auto& e : dna)
        cin >> cnt[e];
    deque<char> pw_stream{pw.begin(), pw.end()}, sub_stream;
    while (p--)
    {
        auto val = pw_stream.front();
        pw_stream.pop_front();
        sub_stream.push_back(val);
        ++sub_cnt[val];
    }
    while (1)
    {
        if (all_of(dna.begin(), dna.end(), [&](const auto& e) {
            return cnt[e] <= sub_cnt[e];
        })) ++res;

        if (pw_stream.empty())
            break;
        auto val = pw_stream.front();
        pw_stream.pop_front();
        sub_stream.push_back(val);
        ++sub_cnt[val];
        --sub_cnt[sub_stream.front()];
        sub_stream.pop_front();
    }
    cout << res;
    return 0;
}