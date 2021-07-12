#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

int main()
{
    map<string, int> m;
    m["a"] = 4;
    m["b"] = 2;
    if (m.count("b"))
    {
        cout << "Exist" << endl;
    }

    for (auto x : m)
    {
        cout << x.first << " = " << x.second << endl;
    }
}