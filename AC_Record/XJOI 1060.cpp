//XJOI 1060
#include<bits/stdc++.h>
using namespace std;
struct Node{
    long long x, y, val;
};
bool cmp(Node x, Node y){
    return x.val < y.val;
}
long long n, m, f[100010], x, y;
Node a[200010];
long long get_(long long x){
    if(f[x] == x) return x;
    f[x] = get_(f[x]);
    return f[x];
}
int main(){
    scanf("%lld%lld", &n, &m);
    for(long long i = 1; i <= m; i++) scanf("%lld%lld%lld", &a[i].x, &a[i].y, &a[i].val);
    sort(a + 1, a + m + 1, cmp);
    for(long long i = 1; i <= n; i++) f[i] = i;
    long long l = 1;
    long long ans = 0;
    for(long long i = 1; i < n; i++){
        x = get_(a[l].x);
        y = get_(a[l].y);
        while(x == y){
            l++;
            x = get_(a[l].x);
            y = get_(a[l].y);
        }
        f[x] = y;
        ans += a[l].val;
    }
    printf("%lld", ans);
    return 0;
}