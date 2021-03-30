// cpp algorithm ps number 49

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    int total = 0;
    cin >> n;
    
    int *front = new int[n];
    int *side = new int[n];

    for (int i = 0; i < n;i++)
        cin >> front[i];
    for (int i = 0; i < n;i++)
        cin >> side[i];

     for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            total += min(front[i], side[j]);
     cout << total;

     return 0;
}