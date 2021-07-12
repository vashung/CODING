#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int binarySearch(int arr[10],int key)
{
    int left, right, mid;
    left = 0;
    right = sizeof(arr)/sizeof(arr[0]) -1;

    while(left <= right)
    {
        mid = (left + right)/2;

        if(key == arr[mid]){
            return mid;
        }
        else if(key < arr[mid])
        {
            right = mid;
        }else{
           left = mid+1;
        }
    }
    return -1;
}

int main()
{

    int ar[] = {1,25,34,,56,58,67,76,84,90,121};

    int result = binarySearch(ar,25);
    if(result ==-1)
    {
        cout << "Not exist"<<endl;
    }
    else
        {
        cout << "Found in  "<< result+1<<" position" <<endl;
    }


    return 0;

}
