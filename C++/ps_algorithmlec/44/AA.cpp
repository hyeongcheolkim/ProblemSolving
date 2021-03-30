// cpp algorithm ps number 44

#include <iostream>
#include <algorithm>


using namespace std;

int count(const int &len,int *&pos, const int &n);

int main()
{
    int n, m, lt,rt, mid, res;
    cin >> n >> m;
    int *pos = new int[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> pos[i];
    sort(pos + 1, pos + n + 1);

    lt = 1;
    rt = pos[n];
    while(lt<=rt)
    {
        mid = (lt + rt) / 2;
        if(count(mid,pos,n)>=m)
        {
            res = mid;
            lt = mid + 1;
        }
        else
            rt = mid - 1;
    }
    cout << res;
    delete[] pos;
    return 0;
}

int count(const int &len, int* &pos, const int &n)
{
    int cnt = 1, cursor = pos[1];
    for (int i = 2; i <= n; i++)
    {
        if (pos[i] - cursor >= len)
        {
            cnt++;
            cursor = pos[i];
        }
    }
    return cnt;
}
