/*
Given a binary string S . Perform R iterations on string S, where in each iteration 
0 becomes 01 and 1 becomes 10. Find the Nth character of the string after performing 
R iterations.

EXAMPLE:
Input:
S = 101
R = 2 
N = 3
Output:
1
Explanation : 
Expand S 2 times and get 1 at third position
*/
#include <bits/stdc++.h>
using namespace std;
char find(string s, int n, int r)
{
    string st = "";

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < s.length(); j++)
        {
            if (s.at(i) == '1')
            {
                st += "10";
            }
            else
            {
                st += "01";
            }
        }
        s = st;
        st = "";
    }
    return s[r];
}

//Geeks solution
char solve(string s, int n, int r)
{
    r++;
    string f; // temporary string;
    long int it = 0, p, i, j, len = 0;
    while (len < r)
    {
        it++;
        len = it * pow(2, n);
    }
    p = pow(2, n);
    r--;
    r = r % p;
    if (it == 0)
        it++;
    f += s[it - 1];

    for (i = 0; i < n; i++)
    {
        s.clear();
        for (j = 0; j < f.length(); j++)
        {
            if (f[j] == '1')
                s += "10";
            else
                s += "01";
        }
        f.clear();
        f += s;
    }
    return f[r];
}
int main()
{
    int n, r;
    string s;

    cin >> s >> n >> r;
    char res = find(s, n, r);
    cout << res << endl;
}