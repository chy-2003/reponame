#include<bits/stdc++.h>
using namespace std;
const long long MAXN = 100010;
long long n, ans, a[MAXN], b[MAXN];
void work(long long l, long long r){
    if(l == r) return;
    work(l, (l + r) >> 1);
    work(((l + r) >> 1) + 1, r);
    long long l1 = l, l2 = ((l + r) >> 1) + 1, ll = l;
    while((l1 <= (l + r) >> 1) && (l2 <= r)){
        if(a[l1] <= a[l2]){
            b[ll] = a[l1];
            ll++; l1++;
        } else{
            b[ll] = a[l2];
            ans += ((l + r) >> 1) - l1 + 1;
            ll++; l2++;
        }
    }
    while(l1 <= ((l + r) >> 1)){
        b[ll] = a[l1];
        ll++; l1++;
    }
    while(l2 <= r){
        b[ll] = a[l2];
        ll++; l2++;
    }
    for(long long i = l; i <= r; i++) a[i] = b[i];
    return;
}
int main(){
    scanf("%lld", &n);
    for(long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
    ans = 0;
    work(1, n);
    printf("%lld", ans);
    return 0;
}
