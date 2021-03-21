//baekjoon 1085 ps

#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main()
{
    int x, y, w, h;
    cin >> x>> y>> w>> h;

    array<int, 4> arr = {x, y, h - y, w - x};
    cout << *min_element(arr.begin(), arr.end()) << endl;
    
    return 0;
}
