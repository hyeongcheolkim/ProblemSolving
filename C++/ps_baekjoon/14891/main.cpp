#include <bits/stdc++.h>
using namespace std;

class Gear
{
private:
    vector<char> polarity;
public:
    Gear() {}
    void set_polarity(vector<char> polarity) { this->polarity = polarity; }
    char get_12clock() { return polarity[0]; }
    char get_3clock() { return polarity[2]; }
    char get_9clock() { return polarity[6]; }
    void rotate_clock()
    {
        std::rotate(polarity.begin(), polarity.end() - 1, polarity.end());
    }
    void rotate_counter_clock()
    {
        std::rotate(polarity.begin(), polarity.begin() + 1, polarity.end());
    }
    void rotate(int direction)
    {
        if (direction == 1)
            rotate_clock();
        if (direction == -1)
            rotate_counter_clock();
    }
};

int k, score;
vector<Gear> gears(4);

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 4; ++i)
    {
        vector<char> tmp;
        for (int j = 0; j < 8; ++j)
        {
            char buff;
            cin >> buff;
            tmp.push_back(buff);
        }
        gears[i].set_polarity(tmp);
    }
    cin >> k;
    while (k--)
    {
        int gear_idx, direction;
        cin >> gear_idx >> direction;
        --gear_idx;
        vector<int> rotate_direction(4);
        rotate_direction[gear_idx] = direction;
        for (int i = gear_idx + 1; i < 4; ++i)
            if (gears[i].get_9clock() != gears[i - 1].get_3clock())
                rotate_direction[i] = -rotate_direction[i - 1];
            else
                break;
        for (int i = gear_idx - 1; i >= 0; --i)
            if (gears[i].get_3clock() != gears[i + 1].get_9clock())
                rotate_direction[i] = -rotate_direction[i + 1];
            else
                break;
        for (int i = 0; i < 4; ++i)
            gears[i].rotate(rotate_direction[i]);
    }
    for (int i = 0; i < 4; ++i)
        if (gears[i].get_12clock() == '1')
            score += pow(2, i);
    cout << score;
    return 0;
}