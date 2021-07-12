//Find the

#include <bits/stdc++.h>
using namespace std;
bool unique(string s)
{
    unordered_map<char, int> um;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s.at(i);
        if (um.count(ch)){
            return false;
        }
        um.insert({ch, 1});
    }
    return true;
}

//Another method using array
bool uniquechar(string s)
{
    char ch[128];

    for (int i = 0; i < s.le ngth(); i++)
    {
        int val = s.at(i);
        if (ch[s.at(i)] == true)
        {
            return false;
        }
        ch[s.at(i)] = true;
        cout<<ch[i]<<endl;
    }
    return true;
}

int main()
{
    string s("a3&8^_)");
    string s2("@#$%^&*)(");
    cout << unique(s) << endl;
    cout << unique(s2) << endl;

    cout << uniquechar(s) << endl;
    cout << uniquechar(s2) << endl;
    return 0;
}