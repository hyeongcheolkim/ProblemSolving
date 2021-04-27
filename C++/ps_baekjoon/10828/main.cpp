//baekjoon ps 10828

#include <iostream>

using namespace std;

class mystack
{
private:
    int *arr;
    int capacity;
    int _size;

public:
    mystack(const int &n)
    {
        arr = new int[n];
        capacity = n;
        _size = -1;
    }
    ~mystack()
    {
        delete[] arr;
    }
    void push(const int &num)
    {
        arr[++_size] = num;
    }
    void pop()
    {
        if (_size == -1)
            cout << _size << '\n';
        else
            cout << arr[_size--] << '\n';
    }
    void size() const
    {
        cout << _size + 1 << '\n';
    }
    void empty() const
    {
        if (_size == -1)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
    void top() const
    {
        if (_size == -1)
            cout << _size << '\n';
        else
            cout << arr[_size] << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    mystack teststack(n);
    for (int i = 0; i < n; i++)
    {
        static string str;
        static int input;
        cin >> str;
        if (str == "push")
        {
            cin >> input;
            teststack.push(input);
        }
        else if (str == "top")
            teststack.top();
        else if (str == "size")
            teststack.size();
        else if (str == "pop")
            teststack.pop();
        else if (str == "empty")
            teststack.empty();
    }
    return 0;
}