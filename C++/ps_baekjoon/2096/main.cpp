//baekjoon ps 2096

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> mini(3);
    vector<int> maxi(3);
    vector<int> input(3);
    vector<int> temp;
    while (n--)
    {
        for (int i = 0; i < input.size(); i++)
            cin >> input[i];
        temp = maxi;
        temp[0] = input[0] + *max_element(maxi.begin(), maxi.end() - 1);
        temp[1] = input[1] + *max_element(maxi.begin(), maxi.end());
        temp[2] = input[2] + *max_element(maxi.begin() + 1, maxi.end());
        maxi = temp;
        temp = mini;
        temp[0] = input[0] + *min_element(mini.begin(), mini.end() - 1);
        temp[1] = input[1] + *min_element(mini.begin(), mini.end());
        temp[2] = input[2] + *min_element(mini.begin() + 1, mini.end());
        mini = temp;
    }
    cout << *max_element(maxi.begin(), maxi.end()) << " " << *min_element(mini.begin(), mini.end());
    return 0;
}
