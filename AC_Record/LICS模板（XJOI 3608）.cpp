#include<cstdio>
#include<algorithm>
 
int n, m, a[510], b[510], f[510][510], ans, rec;
 
int main(){
    ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
    for(int i = 1; i <= n; i++){
        rec = 0;
        for(int j = 1; j <= m; j++){
            f[i][j] = f[i - 1][j];
            if(b[j] < a[i])
            rec = std::max(rec, f[i - 1][j]);
            if(b[j] == a[i]) f[i][j] = rec + 1;
            ans = std::max(ans, f[i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}
