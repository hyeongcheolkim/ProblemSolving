//baekjoon 1181 ps

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>

using namespace std;

bool compare(const string &a, const string &b);

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    string* arr = new string[n];

    for (int i = 0; i < n;i++)
        getline(cin, arr[i]);

    sort(&arr[0], &arr[n], compare);
    auto cursor = unique(&arr[0], &arr[n]);

    for (int i = 0; &arr[i] != cursor;i++)
        cout << arr[i]<<'\n';

    return 0;
}

bool compare(const string &a, const string &b)
{
    if(a.size() != b.size())
        return a.size() < b.size();
    else
        return a < b;
}