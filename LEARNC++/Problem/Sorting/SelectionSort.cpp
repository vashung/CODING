#include <bits/stdc++.h>
using namespace std;
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int pos = i;
        int small = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < small)
            {
                small = arr[j];
                pos = j;
            }
        }
        swap(arr[i], arr[pos]);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    selectionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}