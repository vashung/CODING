#recursion
def tripleStep(n):
    if n < 0:
        return 0
    if n == 0: 
        return 1
    
    return tripleStep(n-1) + tripleStep(n-2) + tripleStep(n - 3)
#DP
arr = {};
def countWays(n):
    if n < 0:
        return 0
    if n == 0:
        return 1
    if n in arr:
        return arr[n];
    arr[n] = countWays(n - 1) + countWays(n-2) + countWays(n-3)
    return arr[n]
    
    
n = 4
result = tripleStep(n)
print(result)
print(countWays(n))

