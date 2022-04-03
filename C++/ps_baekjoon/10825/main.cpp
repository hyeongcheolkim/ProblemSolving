#include <bits/stdc++.h>
using namespace std;

struct grade
{
    string name;
    int korean, english, math;

    grade(const string& name, const int& korean, const int& english, const int& math)
    {
        this->name = name;
        this->korean = korean;
        this->english = english;
        this->math = math;
    }

    bool operator< (const auto& that) const
    {
        if (this->korean == that.korean)
        {
            if (this->english == that.english)
            {
                if (this->math == that.math)
                    return this->name < that.name;
                else
                    return this->math > that.math;
            }
            else
                return this->english < that.english;
        }
        else
            return this->korean > that.korean;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<grade> grade_board;
    grade_board.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        string name;
        int korean, english, math;
        cin >> name >> korean >> english >> math;
        grade_board.emplace_back(name, korean, english, math);
    }
    sort(grade_board.begin(), grade_board.end());
    for (const auto& grade : grade_board)
        cout << grade.name << '\n';
    return 0;
}