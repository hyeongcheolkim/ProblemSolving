//baekjoon ps 5430

#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        static string fnc;
        static string list;
        static int n;
        static bool flag;
        static int R;
        deque<int> arr;
        flag = true;

        cin >> fnc >> n >> list;
        for (int i = 1; i < list.size(); i++)
        {
            if (n == 0)
                break;
            static int temp = 0;
            if (isdigit(list[i]))
                temp = temp * 10 + (list[i] - '0');
            else
            {
                arr.push_back(temp);
                temp = 0;
            }
        }
        R = 0;
        for (int i = 0; i < fnc.size(); i++)
        {

            if (fnc[i] == 'R')
                R++;
            if (fnc[i] == 'D')
            {
                if (arr.empty())
                {
                    flag = false;
                    break;
                }
                if (R % 2 == 0)
                    arr.pop_front();
                else
                    arr.pop_back();
            }
        }
        if (R % 2 == 1)
            reverse(arr.begin(), arr.end());
        if (flag)
        {
            if (arr.empty())
                cout << "[]" << '\n';
            else
            {
                cout << "[" << arr[0];
                for (int i = 1; i < arr.size(); i++)
                    cout << "," << arr[i];
                cout << "]" << '\n';
            }
        }
        else
            cout << "error" << '\n';
    }
    return 0;
}