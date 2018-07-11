#include<bits/stdc++.h>
using namespace std;
int n, m, a[5010], f[5010];
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++){
        f[i] = 1;
        for(int j = 1; j < i; j++)
            if(a[j] <= a[i]) f[i] = max(f[i], f[j] + 1);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, f[i]);
    printf("%d\n", n - ans);
    return 0;
}
