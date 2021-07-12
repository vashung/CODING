#include<iostream.h>
using namespace std;

int shoping(int shirt[], int shoes[], int budget){
    int slen = sizeof(shirt)/sizeof(shirt[0]);
    int ssize = sizeof(shoes)/sizeof(shoes[0]);

    for (int i = 0; i < slen; i++ ){
        for(;int j = ssize; j++ ){
            if( shirt[i] + shoes[j] >= budget){
                    cout<<"[ " <<shirt[i] <<","<< shoes[j]<<" ]" << endl;
            }
        }
    }
}
int main(){
    int slen, ssize;
    cin>>slen>> ssize;
    int shirt[slen];
    cout << "shirt price: "
    for(int i = 0; << slen; i++){
        cin>>shirt[i];
    }
    cout << "shoes price: ";
    int shoes[ssize];
    for(int i = 0; i< ssize; i++){
        cin>>shoes[i];
    }

    shoping(shirt,shoes,25);

}
