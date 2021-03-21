// cpp algorithm ps number 3

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr;
    int n;
    int sum = 0;
    cin >> n;
    for (int i = 1; i < n;i++)
        if(n%i==0)
        {
            arr.push_back(i);
            sum += i;
        }
    for (int i = 0; i < arr.size()-1;i++)
        cout << arr.at(i) << "+";
    cout << arr.back() << "="<<sum;
    return 0;
}