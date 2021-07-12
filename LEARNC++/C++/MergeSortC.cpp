#include<bits/stdc++.h>
using namespace std;

void merge(int a[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1];
    int R[n2];

    for(int i = 0; i < n1; i++ ){
        L[i] = a[left + i - 1];
    }
    for (int i = 0; i < n2; i++){
        R[i] = a[mid + i];
    }
    
    int j = 1;
    int k = 1;
    for (int i = left ; i <= right; i++)
    {
         if(L[j]  <= R[k]){
             a[i] = L[j];
             j = j+1;

         }else
         {
             a[i] = R[k];
             k = k+1;
         }
         
        /* code */
    }

}


void mergeSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr,mid + 1, right);
        merge(arr, left, mid, right);
    }
}


int main()
{
    int ar[ ] = { 2,32,4,33,21,34,23,45,64,20,32,11,122,1};
    mergeSort(ar,0,14);
    for (int i = 0; i<14; i++){
        cout<<ar[i] <<" ";
    }

    return 0;
}