//XJOI 1240
#include<bits/stdc++.h>
using namespace std;
int n, a[1010], f[1010], g[1010];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    f[1] = 1;
    for(int i = 2; i <= n; i++)
     if(a[i] >= a[i - 1]) f[i] = f[i - 1] + 1;
     else f[i] = 1;
    g[n] = 1;
    for(int i = n - 1; i >= 1; i--)
     if(a[i] >= a[i + 1]) g[i] = g[i + 1] + 1;
     else g[i] = 1;
    int ans = 0;
    for(int i = 1; i <= n; i++)
     ans = max(ans, f[i] + g[i] - 1);
    printf("%d", ans);
    return 0;
}