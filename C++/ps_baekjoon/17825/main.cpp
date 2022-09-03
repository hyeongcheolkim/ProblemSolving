#include <bits/stdc++.h>
using namespace std;

struct Node;
Node* start, * goal;
vector<int> dice;
vector<Node*> horses;
int maxi;

struct Node
{
    Node* next = nullptr;
    Node* prev = nullptr;
    Node* next_blue = nullptr;
    int val = 0;
    bool vst = false;
    Node() {}
    Node(const int& val, Node* next)
    {
        this->val = val;
        this->next = next;
    }
};

Node* find_node(const int& find_val)
{
    auto cur = start->next;
    while (cur->val != find_val)
        cur = cur->next;
    return cur;
}

void init()
{
    start = new Node{};
    goal = new Node{};
    start->next = goal;
    goal->prev = start;
    for (int i = 2; i <= 40; i += 2)
    {
        Node* tmp = new Node{};
        tmp->val = i;
        goal->prev->next = tmp;
        goal->prev = tmp;
        tmp->next = goal;
    }
    auto n40 = find_node(40);
    auto n25 = new Node{25, new Node{30, new Node{35, n40}}};
    auto n10 = find_node(10);
    auto n20 = find_node(20);
    auto n30 = find_node(30);
    n10->next_blue = new Node{13, new Node{16, new Node{19, n25}}};
    n20->next_blue = new Node{22, new Node{24, n25}};
    n30->next_blue = new Node{28, new Node{27, new Node{26, n25}}};
}

bool move_horse(int idx, int num)
{
    auto& horse = horses[idx];
    auto tmp = horse;
    if (horse == goal)
        return false;
    if (tmp->next_blue != nullptr)
    {
        --num;
        tmp = tmp->next_blue;
    }
    while (num--)
    {
        tmp = tmp->next;
        if (tmp == goal)
        {
            horse->vst = false;
            horse = goal;
            return true;
        }
    }
    if (tmp->vst)
        return false;
    else
    {
        horse->vst = false;
        horse = tmp;
        horse->vst = true;
        return true;
    }
}

void dfs(int level = 0, int acc = 0)
{
    if (level == 10)
    {
        maxi = max(maxi, acc);
        return;
    }
    for (int idx = 0; idx < 4; ++idx)
    {
        auto& horse = horses[idx];
        auto tmp = horse;
        if (move_horse(idx, dice[level]))
            dfs(level + 1, acc + horse->val);
        horse->vst = false;
        horse = tmp;
        horse->vst = true;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    dice.resize(10);
    for (int i = 0; i < 10; ++i)
        cin >> dice[i];
    init();
    horses.assign(4, start);
    dfs();
    cout << maxi;
    return 0;
}