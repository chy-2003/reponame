#include <bits/stdc++.h>
using namespace std;
long long n, ans;
int main() {
    scanf("%lld", &n);
    ans = 0;
    for(long long i = 2; i <= n; i++) {
        long long x = 1, y = i;
        long long t = 1;
        while(x + 1 < y - 1) {
            t++;
            x++; y--;
        }
        x = n; y = i + 1;
        while(x > y) {
            t++;
            x--; y++;
        }
        ans += (t - 1) * n;
    }
    ans /= 4;
    printf("%lld\n", ans);
    return 0;
}
