#include<bits/stdc++.h>
using namespace std;
struct Node{
    long long x, y, z;
};
Node a[200010];
long long n, m, fa[100010];
bool cmp(Node x, Node y){
    return x.z < y.z;
}
long long get_(long long x){
    if(fa[x] == x) return x;
    fa[x] = get_(fa[x]);
    return fa[x];
}
int main(){
    scanf("%lld%lld", &n, &m);
    for(long long i = 1; i <= n; i++) fa[i] = i;
    for(long long i = 1; i <= m; i++) scanf("%lld%lld%lld", &a[i].x, &a[i].y, &a[i].z);
    sort(a + 1, a + m + 1, cmp);
    long long ans = 0, t1, t2;
    for(long long i = 1; i <= m; i++){
        t1 = get_(a[i].x); t2 = get_(a[i].y);
        if(t1 == t2) continue;
        fa[t1] = t2;
        ans += a[i].z;
    }
    printf("%lld", ans);
    return 0;
}
