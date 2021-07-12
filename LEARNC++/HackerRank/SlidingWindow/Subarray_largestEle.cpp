
/* Given a set of arrays of size N and an integer K , you have to find the maximum integer for each
 and every contiguous subarray of size k for each of the given arrays.
 EXAMPLE:
 2          //    Testcase
5 2         //Size of array and size of window
3 4 6 3 4

7 4         
3 4 5 8 1 4 10
Sample Output

4 6 6 4
8 8 8 10
Explanation

For the first case, the contiguous subarrays of size 2 are {3,4},{4,6},{6,3} and {3,4}. 
The 4 maximum elements of subarray of size 2 are: 4 6 6 4.

For the second case,the contiguous subarrays of size 4 are {3,4,5,8},{4,5,8,1},{5,8,1,4} 
and {8,1,4,10}. The 4 maximum element of subarray of size 4 are: 8 8 8 10.

*/

#include <bits/stdc++.h>
using namespace std;

void findMax(int arr[], int n, int k)
{

    deque<int> d;

    for (int i = 0; i < k; i++)
    {
        while ((!d.empty()) && arr[i] >= arr[d.back()])
            d.pop_back();
        d.push_front(i);
    }
    for (int i = k; i < n; i++)
    {
        cout << arr[d.front()] << " ";
        while ((!d.empty()) && d.front() <= i - k)
            d.pop_front();
        while ((!d.empty()) && arr[i] >= arr[d.back()])
            d.pop_back();

        d.push_back(i);
    }
    cout << arr[d.front()] << endl;
}
int main()
{
    int n, size;

    cin >> n >> size;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    findMax(arr, n, size);
}