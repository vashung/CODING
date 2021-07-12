// Given two sequence, Find, the length(); of the longest subsequence present in both of them.
//   SUbsequence: Sequence that appear in the same relative order not necessarily contigous.
 //eg. abcdefg : abc, abg, bdf, aeg, acefg ...
//
#include<bits/stdc++.h>
using namespace std;

//return lenth
int LCS(string X, string Y, int m , int n)
{
    if(m== 0 || n == 0)return 0;

    if(X.at(m-1) == Y.at(n-1)) return LCS(X, Y, m -1, n -1)+1;

    return max(LCS(X, Y, m-1, n), LCS(X, Y, m , n-1));
}
//Return string
string lcs(string X, string Y, int m , int n)
{
    if(m == 0|| n == 0) return "";
    if(X.at(m-1) == Y.at(n-1))return lcs(X,Y,m-1, n-1) + X.at(m-1);
    return max(lcs(X,Y,m-1,n),lcs(X,Y,m, n-1));
}

// Using DP 
int lcsDP(string X, string Y, int m , int n, auto &mp)
{
    if(m == 0 || n ==0) return 0;

    string key = to_string(m) + "|" + to_string(n);
   
    if(mp.find(key) == mp.end())
    {
        if(X.at(m-1) == Y.at(n - 1))
            mp[key] = lcsDP(X, Y, m -1,n-1, mp) + 1;
        else{
            mp[key] = max(lcsDP(X,Y, m , n-1, mp), lcsDP(X,Y, m -1, n, mp));
        }
    }
    return mp[key];
}


int main()
{
    string X ="ABCBDAB";
    string Y ="BDCABA";
    int m = X.length();
    int n = Y.length();

    cout<<LCS(X, Y, m, n )<<endl;
    cout<<lcs(X,Y,m,n)<<endl;
    //BDAB 4


    unordered_map<string, int> mp;
    cout<<lcsDP(X,Y,m, n , mp);
    return 0;
}