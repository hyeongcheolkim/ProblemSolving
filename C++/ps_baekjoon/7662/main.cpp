//baekjoon ps 7662

#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        multiset<int> arr;
        while (k--)
        {
            char mode;
            int num;
            cin >> mode >> num;
            switch (mode)
            {
            case 'I':
                arr.insert(num);
                break;
            case 'D':
                if (num == 1 && !arr.empty())
                    arr.erase(--arr.end());
                else if (num == -1 && !arr.empty())
                    arr.erase(arr.begin());
                break;
            }
        }
        if (arr.empty())
            cout << "EMPTY" << '\n';
        else
            cout << *--arr.end() << " " << *arr.begin() << '\n';
    }
    return 0;
}