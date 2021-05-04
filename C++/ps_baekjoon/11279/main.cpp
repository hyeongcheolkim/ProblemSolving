//baekjoon ps 11279

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<unsigned int> pq;
    int n;
    cin >> n;
    while(n--)
    {
        static int input;
        cin >> input;
        if(input ==0)
        {
            if(pq.empty())
                cout << 0 << '\n';
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
            pq.push(input);
    }
    return 0;
}