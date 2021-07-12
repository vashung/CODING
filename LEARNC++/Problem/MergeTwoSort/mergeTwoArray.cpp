#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int n, int arr1[], int m, int res[])
{
    int a, b, c;
    for (a = 0, b = 0, c = 0; a < n && b < m;)
    {
        if (arr[a] <= arr1[b])
        {
            res[c++] = arr[a++];
        }
        else
        {
            res[c++] = arr1[b++];
        }
    }

    while (b < m)
    {
        res[c++] = arr1[b++];
    }
}

int main()
{

    int n, m, r;
    cin >> n >> m;
    int arr[n], arr1[m];
    r = n + m;
    int res[r];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> arr1[i];
    }
    merge(arr, n, arr1, m, res);

    for (int i = 0; i < r; i++)
    {
        cout << res[i] << " ";
    }
}