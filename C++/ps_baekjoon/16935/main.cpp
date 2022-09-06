#include <bits/stdc++.h>
using namespace std;

class Mat
{
private:
    vector<vector<int>> datum;
    int row_size;
    int col_size;
public:
    Mat(const vector<vector<int>>& datum, int row_size, int col_size)
    {
        this->datum = move(datum);
        this->row_size = row_size;
        this->col_size = col_size;
    }

    void reverse_up_down() { reverse(datum.begin(), datum.end()); }

    void reverse_left_right() { for_each(datum.begin(), datum.end(), [](auto& e) {reverse(e.begin(), e.end()); }); }

    void rotate_clock()
    {
        vector<vector<int>> tmp(col_size, vector<int>(row_size));
        for (int row = 0; row < row_size; ++row)
            for (int col = 0; col < col_size; ++col)
                tmp[col][row_size - 1 - row] = datum[row][col];
        datum = move(tmp);
        swap(row_size, col_size);
    }

    void rotate_counter_clock()
    {
        vector<vector<int>> tmp(col_size, vector<int>(row_size));
        for (int row = 0; row < row_size; ++row)
            for (int col = 0; col < col_size; ++col)
                tmp[col_size - 1 - col][row] = datum[row][col];
        datum = move(tmp);
        swap(row_size, col_size);
    }

    void rotate_clock_by_group()
    {
        auto tmp = datum;
        for (int row = 0; row < row_size / 2; ++row)
            for (int col = 0; col < col_size / 2; ++col)
            {
                datum[row][col + col_size / 2] = tmp[row][col];
                datum[row + row_size / 2][col + col_size / 2] = tmp[row][col + col_size / 2];
                datum[row + row_size / 2][col] = tmp[row + row_size / 2][col + col_size / 2];
                datum[row][col] = tmp[row + row_size / 2][col];
            }
    }

    void rotate_counter_clock_by_group()
    {
        auto tmp = datum;
        for (int row = 0; row < row_size / 2; ++row)
            for (int col = 0; col < col_size / 2; ++col)
            {
                datum[row + row_size / 2][col] = tmp[row][col];
                datum[row + row_size / 2][col + col_size / 2] = tmp[row + row_size / 2][col];
                datum[row][col + col_size / 2] = tmp[row + row_size / 2][col + col_size / 2];
                datum[row][col] = tmp[row][col + col_size / 2];
            }
    }

    void print()
    {
        for (int row = 0; row < row_size; ++row)
        {
            for (int col = 0; col < col_size; ++col)
                cout << datum[row][col] << ' ';
            cout << '\n';
        }
    }

    void oper(int num)
    {
        switch (num)
        {
            case 1: reverse_up_down(); break;
            case 2: reverse_left_right(); break;
            case 3: rotate_clock(); break;
            case 4: rotate_counter_clock(); break;
            case 5: rotate_clock_by_group(); break;
            case 6: rotate_counter_clock_by_group(); break;
            default: break;
        }
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m, r;
    cin >> n >> m >> r;
    vector<vector<int>> datum(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> datum[i][j];
    Mat mat{datum, n, m};
    while (r--)
    {
        int num;
        cin >> num;
        mat.oper(num);
    }
    mat.print();
    return 0;
}