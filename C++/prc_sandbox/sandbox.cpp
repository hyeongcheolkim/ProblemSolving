#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    int &&num = move(q.front());
    cout << num;
    cout << q.front();
    return 0;
}