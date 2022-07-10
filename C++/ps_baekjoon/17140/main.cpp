#include <bits/stdc++.h>
using namespace std;

int r, c, k;
constexpr int NO_SUCH_ELEMENT = -1;
constexpr int MAX_MATRIX_SIZE = 100;

class Matrix
{
private:
    vector<vector<int>> data;
    int max_row_size;
    int max_col_size;

    void transpose_data()
    {
        vector<vector<int>> data_T(max_col_size, vector<int>(max_row_size));
        for (int i = 0; i < max_row_size; ++i)
            for (int j = 0; j < max_col_size; ++j)
                data_T[j][i] = data[i][j];
        swap(max_row_size, max_col_size);
        this->data = move(data_T);
    }

    void oper_row()
    {
        for (int i = 0; i < max_row_size; ++i)
        {
            unordered_map<int, int> cnt;
            vector<int> tmp;
            for (const auto& e : data[i])
            {
                if (e == 0)
                    continue;
                ++cnt[e];
            }
            vector<pair<int, int>> cnt_vec{cnt.begin(), cnt.end()};
            sort(cnt_vec.begin(), cnt_vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                if (a.second == b.second)
                    return a.first < b.first;
                else
                    return a.second < b.second;
            });
            for (const auto& [val, ea] : cnt_vec)
            {
                if (tmp.size() >= MAX_MATRIX_SIZE)
                {
                    while (tmp.size() > MAX_MATRIX_SIZE)
                        tmp.pop_back();
                    break;
                }
                tmp.push_back(val);
                tmp.push_back(ea);
            }
            max_col_size = max(max_col_size, static_cast<int>(tmp.size()));
            data[i] = move(tmp);
        }
        for (int i = 0; i < max_row_size; ++i)
        {
            int size_diff = max_col_size - data[i].size();
            while (size_diff--)
                data[i].push_back(0);
        }
    }

    void oper_col()
    {
        transpose_data();
        oper_row();
        transpose_data();
    }
public:
    Matrix(const vector<vector<int>>& data, const int& row_size = 3, const int& col_size = 3)
    {
        this->data = move(data);
        max_row_size = row_size;
        max_col_size = col_size;
    }

    int get_data(int row, int col)
    {
        if (!(row < max_row_size && col < max_col_size))
            return NO_SUCH_ELEMENT;
        return data[row][col];
    }

    void oper_sort()
    {
        if (max_row_size >= max_col_size)
            oper_row();
        else
            oper_col();
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> r >> c >> k;
    vector<vector<int>> data(3, vector<int>(3));
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> data[i][j];
    Matrix mat{data};
    for (int tick = 0; tick <= 100; ++tick)
    {
        if (mat.get_data(r - 1, c - 1) == k)
        {
            cout << tick;
            exit(0);
        }
        mat.oper_sort();
    }
    cout << -1;
    return 0;
}