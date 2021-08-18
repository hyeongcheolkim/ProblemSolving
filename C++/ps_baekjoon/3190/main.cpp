//baekjoon ps 3190

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

enum class Direction
{
    UP,
    RIGHT,
    DOWN,
    LEFT,
};

enum class Map
{
    BLANK,
    APPLE,
    OUT_OF_BOUND
};

struct pos
{
    int row, col;
    pos(const int &row, const int &col)
    {
        this->row = row;
        this->col = col;
    }
    bool operator==(const pos &obj) const
    {
        return this->row == obj.row && this->col == obj.col;
    }
};

class Worm
{
private:
    vector<pos> _worm;
    Direction _direct;

public:
    Worm() : _direct(Direction::RIGHT) { _worm.emplace_back(1, 1); }
    bool move()
    {
        auto temp = _worm[0];
        bool crash = false;
        switch (_direct)
        {
        case Direction::UP:
            --temp.row;
            break;
        case Direction::RIGHT:
            ++temp.col;
            break;
        case Direction::DOWN:
            ++temp.row;
            break;
        case Direction::LEFT:
            --temp.col;
            break;
        default:
            break;
        }
        for (int i = _worm.size() - 1; i >= 1; --i)
        {
            if (temp == _worm[i])
                crash = true;
            _worm[i] = _worm[i - 1];
        }
        _worm[0] = temp;
        return crash;
    }
    void set_direct(char direct)
    {
        int temp = static_cast<int>(_direct);
        switch (direct)
        {
        case 'D':
            ++temp;
            if (temp == 4)
                temp = 0;
            break;
        case 'L':
            --temp;
            if (temp == -1)
                temp = 3;
            break;
        default:
            break;
        }
        _direct = static_cast<Direction>(temp);
    }
    void add_tail(const pos &obj) { _worm.push_back(obj); }
    pos get_head() { return _worm[0]; }
    pos get_tail() { return _worm.back(); }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, l, cnt = 0;
    cin >> n >> k;
    vector<vector<Map>> map(n + 2, vector<Map>(n + 2, Map::OUT_OF_BOUND));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            map[i][j] = Map::BLANK;
    while (k--)
    {
        int row, col;
        cin >> row >> col;
        map[row][col] = Map::APPLE;
    }
    cin >> l;
    deque<pair<int, char>> direct(l);
    for (int i = 0; i < l; ++i)
        cin >> direct[i].first >> direct[i].second;
    Worm worm;
    while (++cnt)
    {
        pos tail = worm.get_tail();
        if (worm.move())
            break;
        pos head = worm.get_head();
        if (map[head.row][head.col] == Map::APPLE)
        {
            worm.add_tail(tail);
            map[head.row][head.col] = Map::BLANK;
        }
        if (map[head.row][head.col] == Map::OUT_OF_BOUND)
            break;
        if (!direct.empty())
        {
            auto [time, direction] = direct.front();
            if (cnt == time)
            {
                worm.set_direct(direction);
                direct.pop_front();
            }
        }
    }
    cout << cnt;
    return 0;
}