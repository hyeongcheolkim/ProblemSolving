// cpp algorithm ps number 43

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void calculatesum(const vector<int> &arr, const vector<int> &cursor, vector<int> &sum);

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<int> cursor(m + 1);
    vector<int> sum(m, 0);
    for (auto &e : arr)
        cin >> e;


    for (int i = 0; i < m + 1; i++)
        cursor[i] = n * i /m;
    calculatesum(arr, cursor, sum);
    int max = *max_element(sum.begin(), sum.end());



    for (auto &e : sum)
        cout << e << " ";

    return 0;
}

void calculatesum(const vector<int> &arr, const vector<int> &cursor, vector<int> &sum)
{
    for (int i = 0; i < cursor.size() - 1;i++)
    {
        static int total;
        total = 0;
        for (int j = cursor[i]; j < cursor[i + 1];j++)
            total += arr[j];
        sum[i] = total;
    }       
}