#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <deque>

using namespace std;

int solution(vector<int> food_times, long long k)
{
    int answer = 0;
    deque<pair<int, int>> arr(food_times.size());
    for (int i = 0; i < arr.size(); i++)
        arr[i] = {food_times[i], i + 1};
    sort(arr.begin(), arr.end());
    while (!arr.empty())
    {
        int implier = arr.front().first;
        while (implier * arr.size() > k)
            implier--;
        if (implier > 0)
        {
            k -= implier * arr.size();
            for (int i = arr.size() - 1; i >= 0; i--)
                arr[i].first -= implier;
            while (arr.front().first == 0)
                arr.pop_front();
        }
        else
            break;
    }
    if (arr.empty())
        answer = -1;
    else
        answer = arr[k].second;
    return answer;
}

int main()
{
    vector<int> food_times(3);
    food_times[0] = 3;
    food_times[1] = 1;
    food_times[2] = 2;
    int k = 5;
    cout << solution(food_times, k);
}