#include<bits/stdc++.h>
using namespace std;

int LongestSub(int num[], int n){
    int maxLength = 0;

   vector<int> LIS(n,1);
//initialize all the elements of LIS as 1

    for(int i = 0; i < n ; i++){
        for(int j = 0; j < (i-1); j++){
            if( num[i] > num[j]  && LIS[i] < LIS[j] + 1){
                LIS[i] = LIS[j] + 1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(maxLength < LIS[i]){
            maxLength = LIS[i] +1;
        }
    }

 return maxLength;
}

int main(){
    int array[] = {1,5,65,23,7,45,15,65,45,89,46,210,425,658,7541};

    int n = sizeof(array)/sizeof(array[0]);

    printf("%d",LongestSub(array,n));

}