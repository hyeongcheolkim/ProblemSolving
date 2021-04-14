#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

typedef struct pos
{
    int row, column;
    pos(const int &row, const int &column)
    {
        this->row = row;
        this->column = column;
    }
    int distance(const pos &obj)
    {
        return (abs(this->row - obj.row) + abs(this->column - obj.column));
    }
} pos;

int main()
{
    pos a(1, 2);
    pos b(2, 5);
    cout << a.distance(b);
    return 0;
}

