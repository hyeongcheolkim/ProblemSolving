//baekjoon ps 11723

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

enum class oper
{
    add,
    remove,
    check,
    toggle,
    all,
    empty,
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unordered_map<string, oper> opermap;
    bool set[21];
    for (int i = 1; i <= 20; i++)
        set[i] = false;
    opermap["add"] = oper::add;
    opermap["remove"] = oper::remove;
    opermap["check"] = oper::check;
    opermap["toggle"] = oper::toggle;
    opermap["all"] = oper::all;
    opermap["empty"] = oper::empty;
    int m, num;
    cin >> m;
    while (m--)
    {
        string oper;
        cin >> oper;
        switch (opermap[oper])
        {
        case oper::add:
            cin >> num;
            set[num] = true;
            break;
        case oper::remove:
            cin >> num;
            set[num] = false;
            break;
        case oper::check:
            cin >> num;
            if (set[num])
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
            break;
        case oper::toggle:
            cin >> num;
            if (set[num])
                set[num] = false;
            else
                set[num] = true;
            break;
        case oper::all:
            for (int i = 1; i <= 20; i++)
                set[i] = true;
            break;
        case oper::empty:
            for (int i = 1; i <= 20; i++)
                set[i] = false;
            break;
        default:
            break;
        }
    }
    return 0;
}