//XJOI 3325
#include<bits/stdc++.h>
using namespace std;
int n, a[1010], depth[1010];
int ask(int x){
    if(depth[x] != -1) return depth[x];
    depth[x] = ask(a[x]) + 1;
    return depth[x];
}
int main(){
    scanf("%d", &n);
    for(int i = 2; i <= n; i++) scanf("%d", &a[i]);
    memset(depth, 255, sizeof(depth));
    depth[1] = 1;
    for(int i = 2; i <= n; i++) depth[i] = ask(i);
    int ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, depth[i]);
    printf("%d\n", ans);
    return 0;
}