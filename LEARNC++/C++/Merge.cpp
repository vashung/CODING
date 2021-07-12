#include<bits/stdc++.h>
using namespace std;

int merge(int A[], int B[]){
    int lenA = sizeof(A)/sizeof(A[0]);
    int lenB = sizeof(B)/sizeof(B[0]);
     int size = lenA + lenB;
    int C[size];
    int lenC = sizeof(C)/sizeof(C[0]);

    int ia = 0,ib = 0;
    for(int i = 0; i < lenC; i++){
        if( A[ia] < B[ib]){
            C[i] = A[ia];
            ia++;
        }else{
            C[i] = B[ib];
            ib++;
        }
    }

    for(int i = 0;i < lenC; i++){
        cout << C[i]<<"\t";
    }
   
}
int main(){

    int A[] = {1,3,4,15,20};
    int B[] = {2,5,7,8,10};
    int l = sizeof(A)/sizeof(A[0]);
    int b = sizeof(B)/sizeof(B[0]);
    
    merge(A,B);

}

