//XJO 1478
#include<bits/stdc++.h>
using namespace std;
int f[1010];
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    memset(f, 255, sizeof(f));
    f[0] = 0;
    for(int i = 1; i <= m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        for(int j = n; j >=x; j--){
            if(f[j - x] == -1) continue;
            f[j] = max(f[j], f[j - x] + y);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, f[i]);
    printf("%d", ans);
    return 0;
}