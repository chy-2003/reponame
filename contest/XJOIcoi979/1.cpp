#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, e, cnt[10000010];
int main() {
    scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e);
    for(long long k = a; k <= b; k++)
        for(long long i = 1; i < k; i++)
            for(long long j = 0; j < k; j++) {
                if(i == j) continue;
                long long t = 0, bit = 0;
                for(;;) {
                    bit++;
                    if(bit % 2 == 1) t = t * k + i; else t = t * k + j;
                    if(t > d) break;
                    if(t < c) continue;
                    cnt[t]++;
                }
            }
    for(long long i = c; i <= d; i++)
        if(cnt[i] == e) printf("%lld\n", i);
    return 0;
}
