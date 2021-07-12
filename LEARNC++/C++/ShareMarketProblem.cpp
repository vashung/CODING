#include<bits/stdc++.h>
using namespace std;

int buyAndSell(int stock[], int n){

    int maxProfit = 0,k=0;
    
    //Store all the maxP element as 1
    vector<int>maxP(n,1);
    //ALGO
     /*
       1.compare two element using two array 
       2.get the profit
       3.store the profit in the maxP

       Get the Maximum profit from maxP and return.  

       But this algorithm takes O(n^2) time complexity
     */
    for(int i = 0; i < n-1; i++){
        for(int j = i+1 ; j < n; j++){
         if(stock[i] < stock[j]){
                 maxProfit = stock[j] - stock[i];
                 maxP[k++] = maxProfit;
         }
        }
    }
    for(int i = 0;i < n ; i++){
        if(maxProfit < maxP[i]){
            maxProfit = maxP[i];
        }
    }
    return maxProfit;
}
int main(){
    int array[] = {8,2,1,4,6,3};
    int n = sizeof(array)/sizeof(array[0]);

    printf("%d", buyAndSell(array,n));
}