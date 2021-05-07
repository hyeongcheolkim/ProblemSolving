//baekjoon ps 7562

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct pos
{
    short r;
    short c;
    pos() {}
    pos(const short &r, const short &c)
    {
        this->r = r;
        this->c = c;
    }
    bool isvalid(const short &r, const short &c) const
    {
        return 0 <= this->r && this->r < r && 0 <= this->c && this->c < c;
    }
    bool operator==(const pos &obj) const
    {
        return this->r == obj.r && this->c == obj.c;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    short dr[] = {-1, -1, +1, +1, -2, -2, +2, +2};
    short dc[] = {-2, +2, -2, +2, -1, +1, -1, +1};
    while (t--)
    {
        static short l;
        static pos pos1, pos2;
        cin >> l >> pos1.r >> pos1.c >> pos2.r >> pos2.c;
        vector<vector<int>> check(l, vector<int>(l, 0));
        queue<pos> q;
        q.push(pos1);
        check[pos1.r][pos1.c] = 1;
        while (!q.empty())
        {
            static pos front;
            front = q.front();
            if (front == pos2)
                break;
            q.pop();
            for (int i = 0; i < 8; i++)
            {
                static pos temp;
                temp = pos(front.r + dr[i], front.c + dc[i]);
                if (temp.isvalid(l, l) && !check[temp.r][temp.c])
                {
                    check[temp.r][temp.c] = check[front.r][front.c] + 1;
                    q.push(temp);
                }
            }
        }
        cout << check[q.front().r][q.front().c] - 1<<'\n';
    }
    return 0;
}