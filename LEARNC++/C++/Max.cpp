#include<bits/stdc++.h>
using namespace std;

int findMax(int arr[],int n){
    int max = 0;
    
    for(int i = 0; i < n;i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

int main(){

    int arr[] = { 1,2,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout<<findMax(arr,n);
 }