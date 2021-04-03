#include <iostream>
#include <vector>

using namespace std;

void fnc(vector<vector<int>> &arr, const int &n, const int &m);

int main()
{
    int n = 5, m = 5;
    vector<vector<int>> arr(n,vector<int>(m));
    
    fnc(arr, n, m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << "# ";
}

void fnc( vector<vector<int>> &arr, const int &n, const int &m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            arr[i][j] = i*10+j ;
}