#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n, A, d[100010], sum;
int main(){
    scanf("%lld%lld", &n, &A);
    for(int i = 1; i <= n; i++) scanf("%lld", &d[i]);
    sum = 0;
    for(int i = 1; i <= n; i++) sum += d[i];
    long long l, r;
    for(int i = 1; i <= n; i++){
        l = max(1LL, A - (sum - d[i]));
        r = min(d[i], A - (n - 1));
        printf("%lld ", d[i] - (r - l + 1));
    }
    printf("\n");
    return 0;
}


