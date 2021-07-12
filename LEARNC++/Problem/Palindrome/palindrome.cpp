#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x)
{
    if (x < 0 || (x < != 0 && x % 10 == 0))
        return false;

    int num = 0;
    while (x > num)
    {
        num = num * 10 + x % 10;
        x = x / 10;
    }
    // x is half and num is half;

    return (x == num) || (x == num / 10);
}

bool check(int arr[], int n)
{
    if (n % 2 == 0)
    {
        int m = n / 2 - 1;
        for (int i = 0, j = n - 1; i <= m; i++)
        {
            if (arr[i] != arr[j])
            {
                return false;
            }
            j--;
        }
    }
    else
    {

        for (int i = 0, j = n - 1; i < n / 2; i++)
        {
            if (arr[i] != arr[j])
            {
                return false;
            }
            j--;
        }
    }
    return true;
}
int main()
{
    int arr[] = {0};
    bool res = check(arr, 5);
    cout << res << endl;

    return 0;
}