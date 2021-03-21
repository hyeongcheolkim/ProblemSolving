//baekjoon 7568 ps

#include <iostream>
#include <utility>

using namespace std;

int main()
{
    typedef pair<int, int> spec; // (weight, height)
    int n;

    cin >> n;
    spec *arr = new spec[n];

    for (int i = 0; i < n;i++)
        cin >> arr[i].first >> arr[i].second;
    
    for (int i = 0; i < n;i++)
    {   
        static int rank = 0;
        rank = 0;

        for (int j = 0; j < n;j++)
            if(arr[i].first<arr[j].first && arr[i].second<arr[j].second)
                rank++;

        cout << rank+1 << " ";
    }
        

    return 0;
}