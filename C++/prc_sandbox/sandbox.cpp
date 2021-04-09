#include <iostream>

using namespace std;

class parents
{
    public:
    void print()
    {
        cout << "i'm parents";
    }
}

class child : parents
{
    public:
    void print()
    {
        cout << "i'mchild";
    }
}

int main()
{
    child obj;
    obj.print();
}

