#include<bits/stdc++.h>
using namespace std;
int mergeSort(int[],int,int);

int ksmallest(int arr[],int k){
    int len = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,len-1);
    cout<<"The"<< k <<" th smallest number is: "<< arr[k-1];
}

int merge(int arr[], int left, int mid, int right){
    int len = sizeof(arr)/sizeof(arr[0]);
    int helper[len];
    //copy all the elements of array to the helper array;
    for (int i = left; i <= right; i++){
        helper[i] = arr[i];
    }
    int low = left;
    int rlow = mid + 1;
    int current = left;

    while(low <= mid && rlow <= right){
        if(helper[low] < helper[rlow]){
            arr[current] = helper[low];
            low++;
        }else{
           arr[current] = helper[rlow];
           rlow++;
        }
        current++;
    }
    int remaining = mid - low;
    for(int i = 0; i <= remaining; i++){
        arr[current + i] = helper[low + i];
    }
}
int mergeSort(int arr[], int left ,int right){
    if(left < right){
        int mid = (left + right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


int main(){

    int arr[] = { 7,4,10,3,20,15};
    int k = 3;
    int len = sizeof(arr)/sizeof(arr[0]);
   // mergeSort(arr,0,len-1);
    ksmallest(arr,k);

}
