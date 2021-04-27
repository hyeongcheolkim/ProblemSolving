//baekjoon ps 10773

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int k;
    unsigned long long sum = 0;
    cin >> k;
    stack<unsigned long long> data;
    while(k--)
    {
        static unsigned long long input;
        cin >> input;
        if(input!=0)
            data.push(input);
        else if(input==0)
            data.pop();
    }
    while(!data.empty())
    {
        sum += data.top();
        data.pop();
    }
    cout << sum;
    return 0;
}