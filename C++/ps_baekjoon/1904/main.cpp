//baekjoon ps 1904

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<unsigned long long> fibo(1000010);
    fibo[1] = 1;
    fibo[2] = 2;
    for (int i = 3; i <= n; i++)
        fibo[i] = (fibo[i - 1] + fibo[i - 2])%15746;
    cout << fibo[n]%15746;
    return 0;
}