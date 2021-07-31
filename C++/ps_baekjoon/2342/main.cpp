//baekjoon ps 2342

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

constexpr int MAX_SIZE = 100'000;
int cache[MAX_SIZE][5][5];

int move(int from, int to)
{
    if (from == to)
        return 1;
    switch (from)
    {
    case 0:
        return 2;
    case 1:
        return to == 3 ? 4 : 3;
    case 2:
        return to == 4 ? 4 : 3;
    case 3:
        return to == 1 ? 4 : 3;
    case 4:
        return to == 2 ? 4 : 3;
    default:
        return -1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    vector<int> input;
    input.reserve(MAX_SIZE);
    for (int num; cin >> num && num != 0;)
        input.push_back(num);
    function<int(int, int, int)> recursion = [&](int n, int left, int right)
    {
        if (n == input.size())
            return 0;
        int &ret = cache[n][left][right];
        if (ret != 0)
            return ret;
        return ret = min(move(left, input[n]) + recursion(n + 1, input[n], right),
                         move(right, input[n]) + recursion(n + 1, left, input[n]));
    };
    cout << recursion(0, 0, 0);
    return 0;
}