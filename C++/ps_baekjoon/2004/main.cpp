//baekjoon ps 2004

#include <iostream>

using namespace std;
typedef unsigned long long ull;

struct factor
{
    ull two;
    ull five;
    factor operator +(const factor &obj)const 
    {
        return factor{this->two + obj.two, this->five + obj.five};
    }
    factor operator -(const factor &obj)const 
    {
        return factor{this->two - obj.two, this->five - obj.five};
    }
};

factor fnc(ull n)
{
    ull two = 0;
    ull five = 0;
    for (ull i = 2; i <= n; i *= 2)
        two += n / i;
    for (ull i = 5; i <= n; i *= 5)
        five += n / i;
    return {two, five};
}

int main()
{
    ios_base::sync_with_stdio(false);
    ull n, m;
    cin >> n >> m;
    factor res = fnc(n) - fnc(m) - fnc(n - m);
    cout << min(res.two, res.five);
    return 0;
}