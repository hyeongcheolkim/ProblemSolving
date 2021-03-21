//baekjoon 2447 ps

#include <iostream>
#include <string>

using namespace std;

void star_to_space(int num, char**& arr);

int main()
{
    int n;
    cin >> n;

    //allocate 2nd diemension array (n*n, n=3^k k is natural num)
    char** arr = new char* [n];
    for (int i = 0; i < n; i++)
        arr[i] = new char[n];

    //initialize 2nd arr element's value to '*'
    for (int row = 0; row < n; row++)
        for (int column = 0; column < n; column++)
            arr[row][column] = '*';

    //fnc call
    star_to_space(n, arr);

    //print anwer
    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < n; column++)
            cout << arr[row][column];
        cout << endl;
    }

    return 0;
}

//replace * to ' ' fnc
void star_to_space(int num, char**& arr)
{
    //escape recursion
    if (num == 1)
        return;

    //value
    const static int num_1st_input = num;
    int scope = num;
    num = num / 3;

    //algorithm
    for (int i = 0; i < num_1st_input/scope; i++)
        for (int j = 0; j < num_1st_input/scope; j++)
            for (int row = num + i * scope; row < 2 * num + i * scope; row++)
                for (int column = num + j * scope; column < 2 * num + j * scope; column++)
                    arr[row][column] = ' ';

    //recursion
    return star_to_space(num, arr);
}
