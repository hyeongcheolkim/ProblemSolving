// cpp algorithm ps number 61

#include <iostream>

using namespace std;

int arr[11];
bool tf[11];
bool sign[11];
int counter = 0;

void fnc(int num, const int &n, const int &m);
void calculate(int num, const int &cnt, const int &n, const int &m);

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    fnc(0, n, m);
    cout << counter;
    return 0;
}

void fnc(int num, const int &n, const int &m)
{
    if (num == n)
    {
        static int cnt;
        static int tempsum;
        cnt = 0;
        tempsum = 0;
        for (int i = 0; i < n; i++)
            if (tf[i])
                cnt++;
        calculate(0, cnt, n, m);
        return;
    }
    tf[num] = true;
    fnc(num + 1, n, m);
    tf[num] = false;
    fnc(num + 1, n, m);
}

void calculate(int num, const int &cnt, const int &n, const int &m)
{
    if (num == cnt)
    {
        int tempsum;
        tempsum = 0;
        for (int i = 0, j = 0; i < n; i++)
            if (tf[i])
            {
                if (sign[j++])
                    tempsum += (+arr[i]);
                else
                    tempsum += (-arr[i]);
            }
        if (tempsum == m)
            counter++;
        return;
    }
    sign[num] = true;
    calculate(num + 1, cnt, n, m);
    sign[num] = false;
    calculate(num + 1, cnt, n, m);
}
