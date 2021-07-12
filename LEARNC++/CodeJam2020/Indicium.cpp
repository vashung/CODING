#include <stdio.h>
#include <assert.h>
#include <algorithm>

int impossible() {
    printf("IMPOSSIBLE\n");
    return 0;
}

int solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    if (k < n || k > n*n || k == n+1 || k == n*n-1) return impossible();
    if (k%n == 0) {
        int f = k / n;
        printf("POSSIBLE\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) printf("%d ", (f+j-i+n+n-1)%n+1);
            printf("\n");
        }
        return 0;
    }
    for (int base = 1; base <= n; base++) for (int t1 = 1; t1 <= n; t1++) if (base != t1) {
        int t2 = k - (n-2)*base - t1;
        if (t2 != t1 && t2 != base && 1 <= t2 && t2 <= n) {
            int arr[64];
            arr[0] = base, arr[1] = t1, arr[n-1] = t2;
            for (int i = 1, j = 2; i <= n; i++) if (i != base && i != t1 && i != t2)
                arr[j++] = i;
            printf("POSSIBLE\n");
            for (int i = 0; i < n; i++) {
                int x = i<n-2 ? i : i==n-2 ? n-1 : n-2;
                for (int j = 0; j < n; j++) printf("%d ", arr[(j-x+n)%n]);
                printf("\n");
            }
            return 0;
        }
    }
    if (n == 3) return impossible();
    if (n&1) {
        assert(k == n+2 || k == n*n-2);
        int arr[64][64];
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) arr[i][j] = (j-i+n)%n+1;
        for (int i = n-2; i > 0; i-=2) arr[n-3][i] = i+2;
        arr[n-3][0] = 2; arr[n-3][1] = 4;
        arr[n-2][0] = 4; arr[n-2][1] = 3;
        for (int i = n-4; i > 0; i-=2) arr[n-1][i] = i+4;
        arr[n-1][0] = 3;
        arr[n-2][n-2] = arr[n-1][n-1] = 2;
        arr[n-2][n-1] = arr[n-1][n-2] = 1;
        printf("POSSIBLE\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) printf("%d ", k==n+2?arr[i][j]:(n+1-arr[i][j]));
            printf("\n");
        }
        return 0;
    }
    for (int base = 1; base <= n; base++) {
        int t = k - (n-2)*base;
        if (t&1) continue;
        t /= 2;
        if (1 <= t && t <= n) {
            int arr[2][64];
            arr[0][0] = base, arr[0][1] = t;
            for (int i = 1, j = 2; i <= n; i++) if (i != base && i != t)
                arr[0][j++] = i;
            for (int i = 0; i < n; i++)
                arr[1][i] = arr[0][i];
            std::swap(arr[1][0], arr[1][1]);
            std::rotate(arr[1]+2, arr[1]+3, arr[1]+n);
            printf("POSSIBLE\n");c
            for (int i = 0; i < n; i+=2) {
                int z = (i < 2);
                for (int j = 0; j < n; j++) printf("%d ", arr[ z][(j-i+n)%n]); printf("\n");
                for (int j = 0; j < n; j++) printf("%d ", arr[!z][(j-i+n)%n]); printf("\n");
            }
            return 0;
        }
    }
    return impossible();
}

int main() {
    int T; scanf("%d", &T);
    for (int _ = 1; _ <= T; _++) {
        printf("Case #%d: ", _);
        solve();
    }
    return 0;
}
