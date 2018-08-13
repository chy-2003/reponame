#include <bits/stdc++.h>
using namespace std;
int n, a[110][220];
int testcase = 0;
int read() {
    char ch = getchar(); int t = 0;
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') {
        t = t * 10 + ch - '0';
        ch = getchar();
    }
    return t;
}
int read_() {
    char ch = getchar();
    while(ch != 'O' && ch != 'X') ch = getchar();
    return (ch == 'O') ? 0 : 1;
}
bool check(int i, int j, int k) {
//    printf("Check line = %d, from %d to %d\n", i, j, k);
    for(int l = j; l <= k; l++)
        if(a[i][l] == 1) return false;
    return true;
}
int main() {
    n = read();
    while(n != 0) {
        testcase++;
//        printf("%d\n", n);
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= (n - i) * 2 + 1; j++)
                a[i][j] = read_();
//        printf("*\n");
        int ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= (n - i) * 2 + 1; j++) {
                if(j % 2 == 1) continue;
                int t = 0;
                for(int k = i; k <= n; k++) {
                    if(j - (k - i) * 2 <= 1 || j > (n - k) * 2 + 1) break;
                    if(check(k, j - (k - i) * 2, j)) t += (k - i) * 2 + 1; else break;
                }
//                printf("Down : (%d, %d), count = %d\n", i, j, t);
                ans = max(ans, t);
            }
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= (n - i) * 2 + 1; j++) {
                if(j % 2 == 0) continue;
                int t = 0;
                for(int k = i; k >= 1; k--) {
                    if(check(k, j, j + (i - k) * 2)) t += (i - k) * 2 + 1; else break;
                }
//                printf("Up : (%d, %d), count = %d\n", i, j, t);
                ans = max(ans, t);
            }
        printf("Triangle #%d\n", testcase);
        printf("The largest triangle area is %d\n", ans);
        n = read();
    }
    return 0;
}

