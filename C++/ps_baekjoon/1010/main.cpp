//baekjoon ps 1010

#include <iostream>

using namespace std;

unsigned int memo[35][35];
int combination(unsigned int n, unsigned int k)
{
    if(memo[n][k]!=0)
        return memo[n][k];
    if(n==k || k==0)
        return 1;
    return memo[n][k]=combination(n-1,k)+combination(n-1,k-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unsigned int t;
    cin >> t;
    while (t--)
    {
        static unsigned n, m;
        cin >> n >> m;
        cout << combination(m, n)<<'\n';
    }
    return 0;
}