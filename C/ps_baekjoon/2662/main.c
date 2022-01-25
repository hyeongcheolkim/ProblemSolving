#include <stdio.h>
#include <memory.h>

#define mxN 300
#define mxM 20
int n, m, val[mxN + 1][mxM + 1], trace[mxN + 1][mxM + 1], cache[mxN + 1][mxM + 1];

void trace_company(int cur, int company)
{
    if (company == 0)
        return;
    trace_company(cur - trace[cur][company], company - 1);
    printf("%d ", trace[cur][company]);
    return;
}

int solve(int cur, int company)
{
    if (company == 0)
        return 0;
    int* ret = &cache[cur][company];
    if (*ret != -1)
        return *ret;
    for (int k = 0; k <= cur; ++k)
    {
        int value = solve(k, company - 1) + val[cur - k][company];
        if (*ret < value)
        {
            *ret = value;
            trace[cur][company] = cur - k;
        }
    }
    return *ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        int money;
        scanf("%d", &money);
        for (int j = 1; j <= m; ++j)
            scanf("%d", &val[money][j]);
    }
    printf("%d\n", solve(n, m));
    trace_company(n, m);
    return 0;
}