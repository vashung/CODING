/*Problem: count the numbers of steps to reach N stairs
         Can hop 1 2 and 3 stairs at a time.

Approach: Top down:  To reach n stairs: there can be n - 3 or n - 2 or n - 1;
                     This gives us clue that it can recurse for each and every step until 
                     it gives 0 or less than 0;
                     Base case will be if n < 0 return 0
                                        ifn n == 0 return 1              
*/
#include<bits/stdc++.h>
using namespace std;
// Recursive approach
int tripleStep(int n){
    if(n < 0)return 0;
    if(n == 0) return 1;

    return tripleStep(n-1)+ tripleStep(n-2) + tripleStep(n-3);
}

//using DP
int storage[100];
void init()//Initialize the storage
{
    for(int i  =0; i< 100; i++)
    {
        storage[i] = 0;
    }
}
int countWays(int n)
{
    if(n < 0) return 0;
    if( n  == 0) return 0;

    if(storage[n] !=0)
        return storage[n];
    storage[n] = tripleStep(n-3) + tripleStep(n-2) + tripleStep(n - 1);

    return storage[n];
}

int main()
{
    cout<<tripleStep(4)<<endl;

    init();
    cout<<countWays(36)<<endl; // Began to overflow the bounds of an integer at n = 37
    return 0;    
}