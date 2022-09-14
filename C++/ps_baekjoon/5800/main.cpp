#include <bits/stdc++.h>
using namespace std;

int k;

int main()
{
    cin >> k;
    for (int idx = 1; idx <= k; ++idx)
    {
        int n, maxi_gap = 0;
        cin >> n;
        vector<int> score(n);
        for (int i = 0; i < n; ++i)
            cin >> score[i];
        sort(score.begin(), score.end());
        for (int i = 0; i < n - 1; ++i)
        {
            int gap = score[i + 1] - score[i];
            maxi_gap = max(maxi_gap, gap);
        }
        printf("Class %d\n", idx);
        printf("Max %d, Min %d, Largest gap %d\n", score.back(), score.front(), maxi_gap);
    }
    return 0;
}