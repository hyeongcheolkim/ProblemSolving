// cpp algorithm ps number 45

#include <iostream>
#include <vector>

using namespace std;

class circlearray
{
private:
    int size;
    int cnt;
    vector<int> arr;

public:
    void setsize(int n)
    {
        size = n;
        arr.assign(n, 0);
        cnt = n;
    }
    int &operator[](const int index)
    {
        if (index < 0)
            return arr[(size + index) % size];
        return arr[index % size];
    }
    void remove(int index)
    {
        if (index < 0)
            index = (size + index) % size;
        arr[index % size] = -1;
        cnt--;
    }
    int getcnt()
    {
        return cnt;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    circlearray circlearr;
    circlearr.setsize(n);
    for (int i = 0; i < n; i++)
        circlearr[i] = i + 1;
    while (circlearr.getcnt() != 1)
    {
        static int clock = 0, index = 0;
        if (circlearr[index] > 0)
            clock++;
        if (clock % k == 0&&circlearr[index]>0)
            circlearr.remove(index);
        index++;
    }
    for (int i = 0; i < n; i++)
        if (circlearr[i] > 0)
            cout << circlearr[i] << " ";
    return 0;
}