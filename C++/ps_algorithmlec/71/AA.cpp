// cpp algorithm ps number 71

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main()
{
    int s, e;
    cin >> s >> e;
    queue<int> arr;
    arr.push(s);
    vector<int> trace(10001, 0);
    trace[s] = 1;
    while (!arr.empty())
    {
        static int temp;
        if(arr.front()==e)
            break;
        temp = arr.front();
        
        arr.pop();
        if (temp + 1 <= 10000 && !trace[temp + 1])
        {
            arr.push(temp + 1);
            trace[temp + 1] = trace[temp]+1;
        }
        if (temp + 5 <= 10000 && !trace[temp + 5])
        {
            arr.push(temp + 5);
            trace[temp + 5] = trace[temp]+1;
        }
        if (1 <= temp - 1 && !trace[temp - 1])
        {
            arr.push(temp - 1);
            trace[temp - 1] = trace[temp]+1;
        }
    }
    cout << trace[arr.front()]-1;

    return 0;
}