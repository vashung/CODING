#include <bits/stdc++.h>
#define MAX 100
#define INF 9999
using namespace std;
vector<int> coins;
bool check[MAX];
int val[MAX]; //General recursion
void init()
{
    // coins.push_back(1);
    // coins.push_back(3);
    // coins.push_back(4);

    coins = {1, 3, 4};
    for (int i = 0; i < MAX; i++)
    {
        check[i] = false;
        val[i] = 0;
    }
}
int findMin(int n)
{ // n is the Coin value;
    if (n < 0)
        return INF;
    if (n == 0)
    {
        return 0;
    }
    int best = INF;
    for (auto c : coins)
    {
        best = min(best, findMin(n - c) + 1);
    }
    return best;
}

//DP Memoization
int solve(int n)
{
    if (n < 0)
        return INF;
    if (n == 0)
        return 0;

    int best = INF;
    if (check[n])
        return val[n];
    for (auto c : coins)
    {
        best = min(best, solve(n - c) + 1);
    }

    check[n] = true;
    val[n] = best;
    return best;
}

int main()
{

    init();
    cout << findMin(10) << " " << solve(10) << endl;
}