#include <bits/stdc++.h>
using namespace std;
using point = pair<int, int>;

int n;
vector<point> points;

int distance(point a, point b) { return pow(a.first - b.first, 2) + pow(a.second - b.second, 2); }

int divide_and_conquer(int left, int right)
{
    const int size = right - left + 1;
    const int mid = (left + right) / 2;
    if (size == 2)
        return distance(points[left], points[right]);
    if (size == 3)
        return min({
        distance(points[left], points[mid]),
        distance(points[mid], points[right]),
        distance(points[left], points[right]),
            });
    int ret = min(divide_and_conquer(left, mid), divide_and_conquer(mid + 1, right));
    vector<point> border_points;
    int border = (points[mid].first + points[mid + 1].first) / 2;
    for (int i = left; i <= right; ++i)
        if (pow(border - points[i].first, 2) < ret)
            border_points.push_back(points[i]);
    sort(border_points.begin(), border_points.end(), [](point& a, point& b) {
        return (a.second == b.second ? a.first < b.first : a.second < b.second);
    });
    for (int i = 0; i < border_points.size(); ++i)
        for (int j = i + 1; j < border_points.size(); ++j)
            if (pow(border_points[i].second - border_points[j].second, 2) < ret)
                ret = min(ret, distance(border_points[i], border_points[j]));
            else
                break;
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    points.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> points[i].first >> points[i].second;
    sort(points.begin(), points.end());
    cout << divide_and_conquer(0, n - 1);
    return 0;
}