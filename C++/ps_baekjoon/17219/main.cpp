//baekjoon ps 17219

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unordered_map<string, string> data;
    int n, m;
    cin >> n >> m;
    while (n--)
    {
        string address, pw;
        cin >> address >> pw;
        data[address] = pw;
    }
    while (m--)
    {
        string address;
        cin >> address;
        cout << data[address] << '\n';
    }
    return 0;
}