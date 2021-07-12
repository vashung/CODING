#include <bits/stdc++.h>
#define MAX 100
#define NIL -1
int mem[MAX];

using namespace std;

void init()
{
    for (int i = 0; i < MAX; i++)
    {
        mem[i] = NIL;
    }
}

//From
int fibo(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 1;
    if (mem[n] != NIL)
        return mem[n];
    return mem[n] = fibo(n - 1) + fibo(n - 2);
}

// Using Memoization | Top Down Approcah
int fib(int n)
{

    if (mem[n] == NIL)
    {
        if (n <= 1)
        {
            mem[n] = n;
        }
        else
        {
            mem[n] = fib(n - 1) + fib(n - 2);
        }
    }

    return mem[n];
}

// Using Tabulation Approach
int fibT(int n)
{
    mem[0] = 1;
    mem[1] = 1;
    for (int i = 2; i < n; i++)
    {
        mem[i] = mem[i - 1] + mem[i - 2];
    }
    return mem[n];
}

int main()
{
    int n;
    clock_t begin, end;
    cin >> n;
    init();
    begin = clock();
    cout << fibT(n) << " " << fib(n) << " " << fibo(n) << endl;
    end = clock();

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "Time taken: " << time_spent;

    return 0;
}