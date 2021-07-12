/*  
    Given an array of N numbers. find a contiguos A[i] .. A[j] for which the sum is maximum
    ex Arr[]  = { 1, -3, 4, -2,-1, 6} gives Sum: 7;
*/

#include<bits/stdc++.h>
using namespace std;

//Recursive approach : Time Complexity : O(n^3)
int maxConSeq(int arr[], int size) 
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        for(int j = i; j < size; j++)
        {
            int curSum = 0;
            for(int k = i; k <= j; k++)
            {
                curSum = curSum + arr[k];
                if(curSum > sum){
                    sum = curSum;
                }
            }
        }  
    }
    return sum;
}
// using O(n^2)
int mCS(int arr[], int size)
{
    int sum = 0;
    for(int i = 0; i< size; i++)
    {
        int curSum= 0;
        for(int j = i; j<size; j++)
        {
            curSum= curSum + arr[j];
            if(curSum>sum)
                 sum= curSum;
        }
    } 
    return sum;
}

//Using DP
int maxCS(int arr[], int size){

return 0;
}
int main()
{
    int arr[]  = { 1, -3, 4, -2,-1, 6};
    cout<<maxConSeq(arr, 6)<<endl;
    cout<<mCS(arr,6)<<endl;
    return 0;
}

