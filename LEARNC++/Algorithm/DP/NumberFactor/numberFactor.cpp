/*
    count the nubmer of ways that can form using given sets of nubmer
    Ex, N = 4 , A[] = {1,3,4}
    Output: 4   // {1,1,1,1}, {4}, {1,3}, {3,1}
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> arr;

void init()
{
    arr = {1,3,4};

}
 int nFactor(int n){
     if(n < 0) return 0;
     if(n == 0) return 1;
     
     return 0;
 }
int main()
{
    init();
    cout<<nFactor(4)<<endl;
    return 0;

}