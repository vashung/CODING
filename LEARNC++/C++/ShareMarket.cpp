#include<bits/stdc++.h>
using namespace std;

int StockMarket(int stock[], int n){
    int maxProfit = 0;

    int minStore[n];
    minStore[0] = stock[0];

    //Compare and store the minimum 
    for(int i =1; i < n; i++ ){
        minStore[i] = min(minStore[i-1],stock[i]);
    }

    //Check all the profit and select get the maximum Profit
    for(int i = 0; i < n; i++){
         int profit = stock[i] - minStore[i];
        if(maxProfit < profit){
            maxProfit = profit;
        }
       
    }
    return maxProfit;
}

int main(){
    int array[] = {8,1,2,3,42,5,6,9};
    int n = sizeof(array)/sizeof(array[0]);
     cout<<"The highest Profit among all is: ";
    printf("%d", StockMarket(array,n));
}