#include <bits/stdc++.h>
using namespace std;

int n, res;
vector<string> words;
unordered_map<char, int> coefficient;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    words.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> words[i];
    for (const auto& word : words)
        for (int i = 0; i < word.length(); ++i)
            coefficient[word[i]] += pow(10, word.length() - i - 1);
    vector<pair<char, int>> vec_coefficient{coefficient.begin(), coefficient.end()};
    sort(vec_coefficient.begin(), vec_coefficient.end(), [](const auto& a, const auto& b) {return a.second > b.second; });
    for (int weight = 9; const auto & [alphabet, coef] : vec_coefficient)
        res += coef * weight--;
    cout << res;
    return 0;
}