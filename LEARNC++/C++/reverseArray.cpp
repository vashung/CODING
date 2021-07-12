#include<bits/stdc++.h>
using namespace std;
int reverseArray(int arr[],int len){
    int helper[len];
    int current = len - 1;
    for(int i = 0; i < len; i++){
        helper[current] = arr[i];
        current--;
    }
    for(int i = 0; i < len; i++){
        arr[i] = helper[i];
    }
}
int main(){

    int arr[] = {1,2,3,4,5,7,6,8,9,10,11,12,13,14,15,16,17,18,19,20};

    int len = sizeof(arr)/sizeof(arr[0]);
    reverseArray(arr,len);
    for(int i = 0; i < len; i++ ){
        cout<< arr[i] <<" ";
    }

}
