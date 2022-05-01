#include <bits/stdc++.h>
using namespace std;

string str;
enum class lang_type { CPP, JAVA, ERROR };
lang_type lt;

void error_check()
{
    if (!islower(str.front()))
    {
        lt = lang_type::ERROR;
        return;
    }
    if (lt == lang_type::CPP)
    {
        for (int i = 1; i < str.length(); ++i)
        {
            auto& e = str[i];
            if (e == '_')
            {
                if (!islower(str[i + 1]))
                {
                    lt = lang_type::ERROR;
                    return;
                }
            }
            else if (!islower(e))
            {
                lt = lang_type::ERROR;
                return;
            }
        }
    }
    if (lt == lang_type::JAVA)
    {
        for (const auto& e : str)
            if (!isalpha(e))
            {
                lt = lang_type::ERROR;
                return;
            }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> str;
    if (str.find('_') == string::npos)
        lt = lang_type::JAVA;
    else
        lt = lang_type::CPP;
    error_check();
    if (lt == lang_type::ERROR)
    {
        cout << "Error!";
    }
    if (lt == lang_type::JAVA)
    {
        for (const char& e : str)
        {
            if (isupper(e))
                cout << '_';
            cout << (char)tolower(e);
        }
    }
    if (lt == lang_type::CPP)
    {
        bool upper = false;
        for (const char& e : str)
        {
            if (e == '_')
            {
                upper = true;
                continue;
            }
            if (upper)
            {
                cout << (char)toupper(e);
                upper = false;
            }
            else
                cout << e;
        }
    }
    return 0;
}