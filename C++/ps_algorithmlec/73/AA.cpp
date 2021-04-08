// cpp algorithm ps number 73

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;
    priority_queue<int> arr;
    while(true)
    {
        cin >> n;
        if(n==-1)
            break;
        if(n==0)
            if(arr.empty())
                cout << -1 << '\n';
            else
            {
                cout << arr.top()<<'\n';
                arr.pop();
            }
        if(n>0)
            arr.push(n);
    }
    return 0;
}