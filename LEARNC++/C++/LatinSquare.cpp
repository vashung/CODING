#include<stdio.h>
#include<iostream>
void printHelloWorld();

using namespace std;

int fib(int n , int accumulator){
    if(n == 1) return accumulator;

    accumulator = accumulator * n;
    return fib(n-1, accumulator);
}

void check(char st[]){
    int ch[10];
    int len = 10;
    for(int i = 0 ; i < 10; i++){
        ch[i] = 0;
    }

    for(int i=0;i<10; i++)
    {
        if(ch[st[i]]==1){
            cout<<"Found Repeated word"<<endl;
            break;
        }else{
            ch[st[i]]++;
        }
     if(i==len){
            cout<<"No Repeated words"<<endl;
      }   
    }
}

int main(){

   cout<<"Hello world";
   printHelloWorld();

    int res = fib(5,1);
    cout<<res;

    char ch[] ={'a','b','c','d','a','b','c'};
    return 0;
}

void printHelloWorld(){
    cout<<endl<<"Hello world"<<endl;
}