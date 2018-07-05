//XJOI 1320
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int s, t;
};
int n, f[10010];
Node a[10010];
bool cmp(Node x, Node y){
    return x.s < y.s;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d%d", &a[i].s, &a[i].t);
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++){
        f[i] = 1;
        for(int j = 1; j < i; j++)
         if(a[j].t <= a[i].s) f[i] = max(f[i], f[j] + 1);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, f[i]);
    printf("%d", ans);
    return 0;
}