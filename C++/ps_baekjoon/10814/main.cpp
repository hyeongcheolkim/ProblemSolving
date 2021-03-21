//baekjoon 10814 ps

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef struct
{
    int age;
    string name;
} user;

bool compare(const user &a, const user &b);

int main()
{

    int n;
    cin >> n;
    auto arr = new user[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i].age >> arr[i].name;

    stable_sort(&arr[0], &arr[n],compare);

    for (int i = 0; i < n; i++)
        cout << arr[i].age << " " << arr[i].name << '\n';

    return 0;
}

bool compare(const user &a, const user &b)
{
    return a.age < b.age;
}