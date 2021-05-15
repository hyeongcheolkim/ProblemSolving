//baekjoon ps 2920

#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    string input;
    getline(cin, input);
    if(input == "1 2 3 4 5 6 7 8")
        cout << "ascending";
    else if(input == "8 7 6 5 4 3 2 1")
        cout << "descending";
    else
        cout << "mixed";
    return 0;
}