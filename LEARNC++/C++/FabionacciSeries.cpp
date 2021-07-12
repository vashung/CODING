#include<bits/stdc++.h>
using namespace std;

int fabionacci(int n){
    if(n == 0 || n == 1)
       return n;
     else
        return fabionacci(n-2) + fabionacci(n-1);
}

int fib (int n){
    int a = 0, b = 1,c;
     cout<<a<<"\t"<<b<<"\t";
    for(int i = 0; i < n; i++){
        c = a + b;
        a = b;
        b = c;
        cout<<c<<"\t";
    }
}

int main(){

    int res = fabionacci(10);
    cout << res<<endl;
    int result = fib(10);

}