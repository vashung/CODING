#include <bits/stdc++.h>
using namespace std;

int findPair(int arr[], int n)
{
    int first, second;
    //Update the first and second largest
    if (arr[0] < arr[1])
    {
        first = arr[1];
        second = arr[0];
    }
    else
    {
        first = arr[0];
        second = arr[1];
    }

//Scan through and update the first and second largest element
    for (int i = 2; i < n; i++)
    {
        if (arr[i] > first)
        {
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second && arr[i] != first) // checkin the second largest
        {
            second = arr[i];
        }

//return the sum of the largest pair sum
        return (first + second);
    }
}

int maini()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << findPair(arr, n);
}

int find(int arr[], int n)
{
    int first, second;
    if (arr[0] > arr[1])
    {
        first = arr[0];
        second = arr[1];
    }
    else
    {
        first = arr[1];
        second = arr[0];
    }

    for (int i = 2; i < n; i++)
    {
        if (arr[i] > first)
        {
            second = first;
            first = arr[i];
        }
        else if (arr[i] < first && arr[i] > second)
        {
            second = arr[i];
        }
    }
    return (first + second);
}