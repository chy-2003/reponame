#include <bits/stdc++.h>
using namespace std;
long long n, l, r, mid;
int main() {
    scanf("%lld", &n);
    l = 1; r = max(n, 10LL);
    while(l < r) {
        mid = (l + r) / 2;
        if((long long)floor(1.0 * mid * log10(1.0 * mid)) + 1 >= n) r = mid; else l = mid + 1;
    }
    printf("%lld\n", l);
    return 0;
}

