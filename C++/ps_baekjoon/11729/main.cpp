//baekjoon 11729 ps

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

//ring A. ring B. ring C.
enum ring
{
    A = 1,
    B,
    C,
};

typedef pair<int, int> pos; // (a, b) >> move a to b
void hanoi(int n, ring start, ring via, ring to, unsigned long long &repeat, vector<pos> &arr);
void move(ring start, ring to, unsigned long long &repeat, vector<pos> &arr);

int main()
{
    //result save value
    vector<pos> arr;
    unsigned long long repeat=0; //prevent overflow
    arr.reserve(100000);

    //input n
    int n = 0;
    cin >> n;

    //fnc call
    hanoi(n, A, B, C, repeat, arr);

    //print result
    cout << repeat << '\n';
    for (const auto &e : arr)
        cout << e.first << " " << e.second << '\n';
    return 0;
}

//recursion
void hanoi(int n, ring start, ring via, ring to, unsigned long long &repeat, vector<pos> &arr)
{
    if (n == 1)
        move(start, to, repeat, arr);
    else
    {
        hanoi(n - 1, start, to, via, repeat, arr); //n-1 discus move A to B by C
        move(start, to, repeat, arr); // biggest discus move A to C
        hanoi(n - 1, via, start, to, repeat, arr); // n-1 discus move B to C by A
    }
}

//move fnc
void move(ring start, ring to, unsigned long long &repeat, vector<pos> &arr)
{
    arr.push_back(pos(start, to));
    repeat++;
}