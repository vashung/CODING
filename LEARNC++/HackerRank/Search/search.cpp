#include <bits/stdc++.h>

using namespace std;

vector<int> find(int arr[], int n, int x)
{
    vector<int> res;
    auto k = lower_bound(arr, arr + n, x) - arr;
    auto m = upper_bound(arr, arr + n, x) - arr;
    if (k < n && arr[k] == x)
    {
        res.push_back(k);
        res.push_back(m - 1);
    }

    return res;
}

vector<int> search(int arr[], int n, int x)
{
    vector<int> res;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            cout << " Found at " << mid << endl;
            res.push_back(mid);
            break;
        }
        if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}

int main()
{
    int n, x;
    cin >> n >> x;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans;
    ans = find(arr, n, x);
    cout << "First Occurence of 5 at : " << ans[0] << endl;
    cout << "Last Occurence of 5 at : " << ans[1] << endl;
    // vector<int> ans;
    // ans = find(arr, n, x);
    // cout << ans[0] << " " << ans[1];
}

/*
vector<int> find(int arr[], int n , int x )
{
    int a1=-1;
    int a2=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            a1=i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(arr[i]==x){
            a2=i;
            break;
        }
    }
    return {a1,a2};
}
*/