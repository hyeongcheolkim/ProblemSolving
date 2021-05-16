//baekjoon ps 5639

#include <iostream>
#include <vector>

using namespace std;

void recursion(int lt, int rt, const vector<int> &arr)
{
    if (lt > rt)
        return;

    int root = arr[lt];
    int idx = lt + 1;
    while (idx <= rt)
    {
        if (arr[idx] > root)
            break;
        idx++;
    }
    recursion(lt + 1, idx - 1, arr);
    recursion(idx, rt, arr);
    cout << root << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> arr;
    arr.reserve(10000);
    while (true)
    {
        static int temp;
        cin >> temp;
        if (cin.eof())
            break;
        else
            arr.push_back(temp);
    }
    recursion(0, arr.size() - 1, arr);
    return 0;
}