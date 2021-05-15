//baekjoon ps 10845

#include <iostream>
#include <string>

using namespace std;

struct node
{
    int data;
    node *previous;
    node *next;
    node()
    {
        data = 0;
        next = NULL;
        previous = NULL;
    }
    void setdata(const int &data)
    {
        this->data = data;
    }
    int getdata()
    {
        return this->data;
    }
    void setnext(node *next)
    {
        this->next = next;
    }
    node *getnext()
    {
        return this->next;
    }
    void setprevious(node *previous)
    {
        this->previous = previous;
    }
    node *getprevious()
    {
        return this->previous;
    }
};

class myqueue
{
private:
    node begin;
    node end;
    int _size;

public:
    myqueue()
    {
        begin.setnext(&end);
        end.setprevious(&begin);
        _size = 0;
    }
    void push(const int &n)
    {
        node *temp = new node();
        temp->setdata(n);
        temp->setprevious(end.getprevious());
        temp->setnext(&end);
        (*end.getprevious()).setnext(temp);
        end.setprevious(temp);
        _size++;
    }
    void pop()
    {
        if (_size == 0)
            cout << -1 << '\n';
        else
        {
            cout << (*begin.getnext()).getdata() << '\n';
            node *tempptr = (*begin.getnext()).getnext();
            tempptr->setprevious(&begin);
            delete begin.getnext();
            begin.setnext(tempptr);
            _size--;
        }
    }
    void size()
    {
        cout << _size << '\n';
    }
    void empty()
    {
        if (_size == 0)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
    void front()
    {
        if (_size == 0)
            cout << -1 << '\n';
        else
            cout << (*begin.getnext()).getdata() << '\n';
    }
    void back()
    {
        if (_size == 0)
            cout << -1 << '\n';
        else
            cout << (*end.getprevious()).getdata() << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    myqueue mq;
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        static string str;
        static int input;
        cin >> str;
        if (str == "push")
        {
            cin >> input;
            mq.push(input);
        }
        else if (str == "pop")
            mq.pop();
        else if (str == "size")
            mq.size();
        else if (str == "empty")
            mq.empty();
        else if (str == "front")
            mq.front();
        else if (str == "back")
            mq.back();
    }
    return 0;
}