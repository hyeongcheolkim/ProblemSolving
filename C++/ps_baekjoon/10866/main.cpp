//baekjoon ps xx

#include <iostream>
#include <deque>
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
        next = nullptr;
        previous = nullptr;
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

class mydeque
{
private:
    node begin;
    node end;
    int _size;

public:
    mydeque()
    {
        begin.setnext(&end);
        end.setprevious(&begin);
        _size = 0;
    }
    void push_front(const int &n)
    {
        node *temp = new node();
        temp->setdata(n);
        temp->setnext(begin.getnext());
        temp->setprevious(&begin);
        (*begin.getnext()).setprevious(temp);
        begin.setnext(temp);
        _size++;
    }
    void push_back(const int &n)
    {
        node *temp = new node();
        temp->setdata(n);
        temp->setprevious(end.getprevious());
        temp->setnext(&end);
        (*end.getprevious()).setnext(temp);
        end.setprevious(temp);
        _size++;
    }
    void pop_front()
    {
        if (_size == 0)
            cout << -1 << '\n';
        else
        {
            cout << (*begin.getnext()).getdata() << '\n';
            node *tempptr = (*begin.getnext()).getnext();
            delete begin.getnext();
            begin.setnext(tempptr);
            tempptr = nullptr;
            _size--;
            delete tempptr;
        }
    }
    void pop_back()
    {
        if (_size == 0)
            cout << -1 << '\n';
        else
        {
            cout << (*end.getprevious()).getdata() << '\n';
            node *tempptr = (*end.getprevious()).getprevious();
            delete end.getprevious();
            end.setprevious(tempptr);
            tempptr = nullptr;
            _size--;
            delete tempptr;
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
    mydeque dq;
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        static string str;
        static int input;
        cin >> str;
        if (str == "push_front")
        {
            cin >> input;
            dq.push_front(input);
        }
        else if (str == "push_back")
        {
            cin >> input;
            dq.push_back(input);
        }
        else if (str == "pop_front")
            dq.pop_front();
        else if (str == "pop_back")
            dq.pop_back();
        else if (str == "size")
            dq.size();
        else if (str == "empty")
            dq.empty();
        else if (str == "front")
            dq.front();
        else if (str == "back")
            dq.back();
    }
    return 0;
}