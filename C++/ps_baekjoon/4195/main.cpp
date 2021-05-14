//baekjoon ps 4195

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct integer
{
    int x;
    integer(const int &x)
    {
        this->x = x;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        unordered_map<string, int> arr;
        unordered_map<string, int>::iterator iter1, iter2;
        unordered_map<int, integer *> cnt;
        int f;
        cin >> f;
        while (f--)
        {
            static string n1, n2;
            cin >> n1 >> n2;
            iter1 = arr.find(n1);
            iter2 = arr.find(n2);
            if (iter1 == arr.end() && iter2 == arr.end())
            {
                arr[n1] = arr.size();
                arr[n2] = arr[n1];
                cnt[arr[n1]] = new integer(2);
            }
            else if (iter1 == arr.end())
            {
                arr[n1] = arr[n2];
                cnt[arr[n1]]->x++;
            }
            else if (iter2 == arr.end())
            {
                arr[n2] = arr[n1];
                cnt[arr[n2]]->x++;
            }
            else if (cnt[arr[n1]] != cnt[arr[n2]])
            {
                cnt[arr[n1]]->x += cnt[arr[n2]]->x;
                integer *tempn1 = cnt[arr[n1]];
                integer *tempn2 = cnt[arr[n2]];
                for (auto &e : cnt)
                    if (e.second == tempn2)
                        e.second = tempn1;
            }
            cout << cnt[arr[n1]]->x << '\n';
        }
    }
    return 0;
}