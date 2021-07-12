#include <bits/stdc++.h>
using namespace std;
int swap(int *a, int *b)
{
    int tem = *a;
    *a = *b;
    *b = tem;
}

int partition(int arr[], int l, int r)
{
    int p = arr[r];
    int i = (l - 1);
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= p)
        {
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return (i + 1);
}

int rpartition(int arr[], int l, int r)
{
    int p, n, temp;
    n = rand();
    p = l + n % (r - l + 1);
    swap(&arr[r], &arr[p]);
    return partition(arr, l, r);
}

void kthSmallest(int arr[], int l, int r)
{
    if (l < r)
    {
        int p = rpartition(arr, l, r);
        kthSmallest(arr, l, p - 1);
        kthSmallest(arr, p + 1, r);
    }
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int arr_size;
        cin >> arr_size;
        int arr[arr_size];

        for (int i = 0; i < arr_size; i++)
        {
            cin >> arr[i];
        }
        int k;
        cin >> k;
        kthSmallest(arr, 0, arr_size - 1);

        for (int i = 0; i < arr_size; i++)
            cout << arr[i] << " ";
    }

    return 0;
}
/*
void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    // finding the pivot element and partition the array along that
    int randomPartition(int arr[], int l, int r)
    {
        int n = r-l+1;
        int pivot = rand() % n;
        swap(&arr[l + pivot], &arr[r]);
        return partition(arr, l, r);
    }
    int kthSmallest(int arr[], int l, int r, int k)
    {
        // If k is smaller than number of elements in array
        if (k > 0 && k <= r - l + 1)
        {
            // find a position for random partition
            int pos = randomPartition(arr, l, r);
            
            // if this pos gives the kth smallest element, then return
            if (pos-l == k-1)
                return arr[pos];
                
            // else recurse for the left and right half accordingly
            if (pos-l > k-1)  
                return kthSmallest(arr, l, pos-1, k);
            return kthSmallest(arr, pos+1, r, k-pos+l-1);
        }
    
        return 99999999;
    }
     
    // partitioning the array along the pivot
    int partition(int arr[], int l, int r)
    {
        int x = arr[r], i = l;
        for (int j = l; j <= r - 1; j++)
        {
            if (arr[j] <= x)
            {
                swap(&arr[i], &arr[j]);
                i++;
            }
        }
        swap(&arr[i], &arr[r]);
        return i;
    }
*/