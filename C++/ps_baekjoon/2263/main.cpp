//baekjoon ps 2263

#include <iostream>

using namespace std;

int n;
int *inorder;
int *postorder;
int *idx;
void recursion(int ilt, int irt, int plt, int prt)
{
    if (ilt > irt || plt > prt)
        return;
    int root = idx[postorder[prt]];
    cout << inorder[root] << " ";
    recursion(ilt, root - 1, plt, plt + root - ilt - 1);
    recursion(root + 1, irt, plt + root - ilt, prt - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    inorder = new int[n + 1];
    postorder = new int[n + 1];
    idx = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> inorder[i];
        idx[inorder[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        cin >> postorder[i];
    recursion(1, n, 1, n);
    return 0;
}