#include <bits\stdc++.h>

using namespace std;
int merge(int arr[], int left, int mid, int right)
{
    int len = sizeof(arr) / sizeof(arr[0]);
    int helper[len];
    for (int i = left; i <= right; i++)
    {
        helper[i] = arr[i];
    }

    int low = left;
    int rleft = mid + 1;
    int current = left;

    while (low <= mid && rleft <= right)
    {
        if (helper[low] <= helper[rleft])
        {
            arr[current] = helper[low];
            low++;
        }
        else
        {
            arr[current] = helper[rleft];
            rleft++;
        }
        current++;
    }

    int remaining = mid - low;
    for (int i = 0; i <= remaining; i++)
    {
        arr[current + i] = helper[low + i];
    }
}

int mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15, 45, 6, 12, 45, 87, 96, 85, 32, 65, 45, 47, 31, 25};
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    mergeSort(arr, 0, len - 1);

    return 0;
}
