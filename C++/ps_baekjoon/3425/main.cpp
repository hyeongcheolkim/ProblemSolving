#include <bits/stdc++.h>
using namespace std;

enum class oper { NUM, POP, INV, DUP, SWP, ADD, SUB, MUL, DIV, MOD, END };
map<string, oper> oper_dict
{
    {"NUM", oper::NUM},
    {"POP", oper::POP},
    {"INV", oper::INV},
    {"DUP", oper::DUP},
    {"SWP", oper::SWP},
    {"ADD", oper::ADD},
    {"SUB", oper::SUB},
    {"MUL", oper::MUL},
    {"DIV", oper::DIV},
    {"MOD", oper::MOD},
    {"END", oper::END},
};

class GoStack
{
private:
    vector<string> operation;
    stack<long long> s;
    bool err_flag;
public:
    GoStack(vector<string>& operation) : operation{operation} {};
    void set_init_val(long long num)
    {
        err_flag = false;
        stack<long long> temp;
        s.swap(temp);
        s.push(num);
    }
    void exec()
    {
        for (const auto& e : operation)
        {
            if (err_flag)
                break;
            auto sub_oper = e.substr(0, 3);
            switch (oper_dict[sub_oper])
            {
                case oper::NUM: NUM(stoi(e.substr(4))); break;
                case oper::POP: POP(); break;
                case oper::INV: INV(); break;
                case oper::DUP: DUP(); break;
                case oper::SWP: SWP(); break;
                case oper::ADD: ADD(); break;
                case oper::SUB: SUB(); break;
                case oper::MUL: MUL(); break;
                case oper::DIV: DIV(); break;
                case oper::MOD: MOD(); break;
                case oper::END: break;
                default: ERR(); break;
            }
        }
        if (s.size() != 1)
            err_flag = true;
        if (err_flag)
            cout << "ERROR" << '\n';
        else
            cout << s.top() << '\n';
    }
    void ERR() { err_flag = true; }
    void NUM(int x) { s.push(x); }
    void POP()
    {
        if (s.empty()) { ERR(); return; }
        s.pop();
    }
    void INV()
    {
        if (s.empty()) { ERR(); return; }
        auto first = s.top();
        s.pop();
        s.push(-first);
    }
    void DUP()
    {
        if (s.empty()) { ERR(); return; }
        s.push(s.top());
    }
    void SWP()
    {
        if (s.size() < 2) { ERR(); return; }
        auto first = s.top();
        s.pop();
        auto second = s.top();
        s.pop();
        s.push(first);
        s.push(second);
    }
    void ADD()
    {
        if (s.size() < 2) { ERR(); return; }
        auto first = s.top();
        s.pop();
        auto second = s.top();
        s.pop();
        if (long long res = first + second; abs(res) > 1e9)
        {
            ERR();
            s.push(second);
            s.push(first);
        }
        else
            s.push(res);
    }
    void SUB()
    {
        if (s.size() < 2) { ERR(); return; }
        auto first = s.top();
        s.pop();
        auto second = s.top();
        s.pop();
        if (long long res = second - first; abs(res) > 1e9)
        {
            ERR();
            s.push(second);
            s.push(first);
        }
        else
            s.push(res);
    }
    void MUL()
    {
        if (s.size() < 2) { ERR(); return; }
        auto first = s.top();
        s.pop();
        auto second = s.top();
        s.pop();
        if (long long res = second * first; abs(res) > 1e9)
        {
            ERR();
            s.push(second);
            s.push(first);
        }
        else
            s.push(res);
    }
    void DIV()
    {
        if (s.size() < 2) { ERR(); return; }
        auto first = s.top();
        if (first == 0) { ERR(); return; }
        s.pop();
        auto second = s.top();
        s.pop();
        s.push(second / first);
    }
    void MOD()
    {
        if (s.size() < 2) { ERR(); return; }
        auto first = s.top();
        if (first == 0) { ERR(); return; }
        s.pop();
        auto second = s.top();
        s.pop();
        s.push(second % first);
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    string input;
    int n;
    while (getline(cin, input), input != "QUIT")
    {
        vector<string> inputs;
        if (input.empty())
            continue;
        while (input != "END")
        {
            inputs.push_back(input);
            getline(cin, input);
        }
        GoStack gs(inputs);
        cin >> n;
        while (n--)
        {
            int num;
            cin >> num;
            gs.set_init_val(num);
            gs.exec();
        }
        cout << '\n';
    }
    return 0;
}