#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;

constexpr int mxN = 20, out_of_bound = -1, GUEST = 2, dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
int n, m, fuel, terrain[mxN + 2][mxN + 2];
bool vst[mxN + 2][mxN + 2];
vector<pos> guests;
queue<pos> q, temp;
pos taxi, dst[mxN + 2][mxN + 2];

bool find_dst(pos destination)
{
    while (!q.empty())
    {
        auto [r, c] = q.front();
        if (pos{r, c} == destination)
            return true;
        q.pop();
        for (int direction = 0; direction < 4; ++direction)
        {
            int nr = r + dr[direction];
            int nc = c + dc[direction];
            if (terrain[nr][nc] == out_of_bound || vst[nr][nc])
                continue;
            temp.emplace(nr, nc);
            vst[nr][nc] = true;
        }
    }
    q.swap(temp);
    return false;
}

bool find_guest()
{
    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        if (terrain[r][c] == GUEST)
            guests.emplace_back(r, c);
        for (int direction = 0; direction < 4; ++direction)
        {
            int nr = r + dr[direction];
            int nc = c + dc[direction];
            if (terrain[nr][nc] == out_of_bound || vst[nr][nc])
                continue;
            temp.emplace(nr, nc);
            vst[nr][nc] = true;
        }
    }
    q.swap(temp);
    return !guests.empty();
}

void clear()
{
    for (const auto &e : {&q, &temp})
        while (!e->empty())
            e->pop();
    memset(vst, false, sizeof(vst));
    guests.resize(0);
}

void init()
{
    memset(terrain, out_of_bound, sizeof(terrain));
    guests.reserve(400);
    cin >> n >> m >> fuel;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> terrain[i][j];
            if (terrain[i][j] == 1)
                terrain[i][j] = out_of_bound;
        }
    cin >> taxi.first >> taxi.second;
    for (int i = 0; i < m; ++i)
    {
        pos from, to;
        cin >> from.first >> from.second >> to.first >> to.second;
        terrain[from.first][from.second] = GUEST;
        dst[from.first][from.second] = to;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    init();
    int move = 0;
    bool flag = false;
    while (m--)
    {
        clear();
        vst[taxi.first][taxi.second] = true;
        q.emplace(taxi);
        for (move = 0, flag = false; !q.empty(); ++move)
            if (find_guest())
            {
                flag = true;
                break;
            }
        fuel -= move;
        if (fuel < 0 || !flag)
        {
            fuel = -1;
            break;
        }
        sort(guests.begin(), guests.end());
        auto guest = guests.front();
        terrain[guest.first][guest.second] = 0;
        taxi = guest;
        clear();
        vst[guest.first][guest.second] = true;
        q.emplace(taxi);
        auto destination = dst[guest.first][guest.second];
        for (move = 0, flag = false; !q.empty(); ++move)
            if (find_dst(destination))
            {
                flag = true;
                break;
            }
        fuel -= move;
        if (fuel < 0 || !flag)
        {
            fuel = -1;
            break;
        }
        taxi = destination;
        fuel += move * 2;
    }
    cout << fuel;
    return 0;
}