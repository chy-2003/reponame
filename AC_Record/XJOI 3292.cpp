//XJOI 3292
#include<bits/stdc++.h>
using namespace std;
int n, a[200010];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    a[0] = 0;
    long long ans = 0;
    for(int i = 1; i <= n; i++) ans += abs(a[i] - a[i - 1]);
    printf("%lld", ans);
    return 0;
}