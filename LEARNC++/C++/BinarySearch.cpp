#include<bits/stdc++.h>
using namespace std;
ifstream f("data.in");
ofstream g("data.out");
int A[1000],input;
int binarySearch(int key){
    int left = 1;
    int right = input;
    int mid;
    
    while(left <= right){
        mid = (left + right)/2;
        if(key == A[mid]){
            return mid;
        }else if(key < A[mid]){
            right = mid;
        }else
        {
            left = mid+1;
        }    
    }
    return -1;
}

int main(){
    f>>input;
   
  
  for(int i =1 ; i<= input;++i){
      f>>A[i];
  }

   cout<<binarySearch(19);
  /*
  
  return 0
   int result  = binarySearch(ar,54);
   if(result == -1){
       cout<<" Not found!"<<endl;
   }else{
       cout<<" Found in "<<result+1<<" position."<<endl;
   }

  */
 
 return 0;
}