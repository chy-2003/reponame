//XJOI 3361
#include<bits/stdc++.h>
using namespace std;
int n, m, a[100010], first[100010], l, next[200010], val[200010];
int x, y;
int cnt[100010], maxnum[100010], vis[100010];
int ans;
void add(int x, int y){
    l++;
    next[l] = first[x];
    first[x] = l;
    val[l] = y;
    return;
}
void work(int x, int fa){
    vis[x] = 1;
    cnt[x] = (a[x] != 0)? cnt[fa] + 1 : 0;
    maxnum[x] = max(maxnum[fa], cnt[x]);
    int b = 0;
    for(int i = first[x]; i; i = next[i]){
        if(vis[val[i]] == 0){
            work(val[i], x);
            b = 1;
        }
    }
    if(b == 0){
        if(maxnum[x] <= m) ans++;
    }
    return;
}
int main(){
    l = 0;
    scanf("%d%d", &n, &m);
    memset(first, 0, sizeof(first));
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i < n; i++){
        scanf("%d%d", &x, &y);
        add(x, y); add(y, x);
    }
    memset(cnt, 0, sizeof(cnt));
    memset(maxnum, 0, sizeof(maxnum));
    ans = 0;
    memset(vis, 0, sizeof(vis));
    work(1, 0);
    printf("%d\n", ans);
//  for(int i = 1; i <= n; i++) printf("%d ", maxnum[i]); printf("\n");
//  for(int i = 1; i <= n; i++) printf("%d ", cnt[i]); printf("\n");
    return 0;
}