//baekjoon ps 1991

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, vector<char>> map;

void preorder(char node)
{
    if (node == '.')
        return;
    if (map[node].size() == 2)
    {
        cout << node;
        preorder(map[node][0]);
        preorder(map[node][1]);
    }
}
void inorder(char node)
{
    if (node == '.')
        return;
    if (map[node].size() == 2)
    {
        inorder(map[node][0]);
        cout << node;
        inorder(map[node][1]);
    }
}
void postorder(char node)
{
    if (node == '.')
        return;
    if (map[node].size() == 2)
    {
        postorder(map[node][0]);
        postorder(map[node][1]);
        cout << node;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--)
    {
        static char a, b, c;
        cin >> a >> b >> c;
        map[a].push_back(b);
        map[a].push_back(c);
    }
    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    return 0;
}