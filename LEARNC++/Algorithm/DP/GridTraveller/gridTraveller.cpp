#include <bits/stdc++.h>
#define MAX 100
int arr[MAX][MAX];
using namespace std;

void init()
{
    for (int i = 0; i < MAX; i++)
    {
        arr[i][0] = 0;
    }
    for (int i = 0; i < MAX; i++)
    {
        arr[0][i] = 0;
    }
}

//General Recursive approacth
int gridTravel(int m, int n)
{
    if (m == 1 && n == 1)
    {
        return 1;
    }
    if (m == 0 || n == 0)
        return 0;

    return gridTravel(m - 1, n) + gridTravel(m, n - 1);
}

//DP
int gridT(int m, int n)
{
    if (m == 1 && n == 1)
        return 1;
    if (m == 0 || n == 0)
        return 0;

    if (arr[m][n] != 0)
    {
        cout << "E: " << m << " " << n << endl;
        return arr[m][n];
    }

    arr[m][n] = gridT(m - 1, n) + gridT(m, n - 1);
    cout << m << " " << n << endl;
    return arr[m][n];
}

int main()
{

    int m, n;
    init();
    // cout << gridTravel(1, 1) << endl;
    // cout << gridTravel(2, 3) << endl;
    // cout << gridTravel(3, 3) << endl;
    //cout << gridTravel(18, 18) << endl;

    cout << "DP" << endl;
    // cout << gridT(4, 4) << endl;
    cout << gridT(3, 3) << endl;
    // cout << gridT(3, 2) << endl;
    // cout << gridT(18, 18) << endl;
    // cout << gridT(20, 20) << endl;
}
