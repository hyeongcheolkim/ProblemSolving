// cpp algorithm ps number 85

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int n;
int num_operator[4];
int maximum = INT_MIN;
int minimum = INT_MAX;

void dfs(int level, int sum, const vector<int> &arr)
{
    if (level == n - 1)
    {
        if (sum > maximum)
            maximum = sum;
        if (sum < minimum)
            minimum = sum;
        return;
    }
    for (int i = 0; i < 4; i++)
        if (num_operator[i] > 0)
            switch (i)
            {
            case 0:
                num_operator[0]--;
                dfs(level + 1, sum + arr[level + 1], arr);
                num_operator[0]++;
                break;
            case 1:
                num_operator[1]--;
                dfs(level + 1, sum - arr[level + 1], arr);
                num_operator[1]++;
                break;
            case 2:
                num_operator[2]--;
                dfs(level + 1, sum * arr[level + 1], arr);
                num_operator[2]++;
                break;
            case 3:
                num_operator[3]--;
                dfs(level + 1, sum / arr[level + 1], arr);
                num_operator[3]++;
                break;
            }
}

int main()
{
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < 4; i++)
        cin >> num_operator[i];
    dfs(0, arr[0], arr);
    cout << maximum << "\n"
         << minimum;
    return 0;
}