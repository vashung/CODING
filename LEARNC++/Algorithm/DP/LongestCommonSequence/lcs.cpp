// Given two sequence, Find, the length(); of the longest subsequence present in both of them.
// SUbsequence: Sequence that appear in the same relative order not necessarily contigous.
 //eg. abcdefg : abc, abg, bdf, aeg, acefg ...
//
#include<bits/stdc++.h>
using namespace std;

/*
  The given function is a general recursive approach and its Time Complexity is O(2^n)
  It returns the longest common subsequence length 
  
  This approach checks the string of X and Y; 
  X = A B  C  B D A B
  Y =   BD CA B   A
  
  Three cases arise
  1. if X[i] = Y[j]  :  LCS(i+1, j+1) + 1;   if the character of X and Y are same increment the count and recurse both 
  2. if X[i] != Y[j] : LCS(i+1, j);
  3. if X[i] != Y[j] : LCS(i, j+1);
*/
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

/*
  This approach is Using Dynamic Programming
  An Approach improve from the recursive function
  This is top Down approach which use memoization
  
  Time Complexity : O(n*m);
  
  Instead of calculating repeatedly, it stores the result of every once calculated solution

*/
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
