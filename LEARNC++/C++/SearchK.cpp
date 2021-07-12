#include<bits/stdc++.h>

using namespace std;


int search(int array[],int k){

  int n = sizeof(array)/sizeof(array[0]);
  int i =0;
  while(i < n && array[i] != k){
       i = i+1;
    if(i < n){
      return i;
    }
    else
      {
          return -1;
      }
  }
   
}
int main(){
  int array[] = { 14,13,53,23,15,64,35,64,743,34,3,45,54};
  cout<<search(array,23);

}