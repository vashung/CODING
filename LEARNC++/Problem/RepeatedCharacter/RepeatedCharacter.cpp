#include <bits/stdc++.h>
using namespace std;

string check(string str)
{
    int repeated[126] = {0}, index;
    for (int i = 0; i < str.length(); i++)
    {
        index = str[i];
        repeated[index]++;
    }
}

int main()
{
    string str;
    getline(cin, str);
    int index = str[0];
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //get an array of size 126 and fill with 0;
    // int Frequency[126] = {0}, index;

    // for (int i = 0; i < str.length(); i++)
    // {
    //     index = str[i];
    //     Frequency[index]++;
    // }
    // for (int i = 0; i < str.length(); i++)
    // {
    //     cout << str[i] << Frequency[str[i]];
    //     i = i + (Frequency[str[i]] - 1);
    // }
}