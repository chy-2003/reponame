#include<bits/stdc++.h>
using namespace std;
const int MAXTAG = 531441;
int n, m;
struct three{
    int num[11];
};
int dp[MAXTAG][11], l, r, q_vis[MAXTAG << 3], q_pos[MAXTAG << 3], a[11][11];
three unpacked(int x){
    three t;
    memset(t.num, 0, sizeof(t.num));
    for(int i = 1; i <= n; i++){
        t.num[i] = x % 3;
        x /= 3;
    }
    return t;
}
int packed(three t){
    int x = 0;
    for(int i = n; i >= 1; i--){
        x = x * 3 + t.num[i];
    }
    return x;
}
bool none_empty(int x){
    three tt = unpacked(x);
    for(int i = 1; i <= n; i++) if(tt.num[i] == 0) return false;
    return true;
}
int main(){
    while(scanf("%d%d", &n, &m) == 2){
        memset(a, 255, sizeof(a));
        for(int i = 1; i <= m; i++){
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            if(a[x][y] == -1){
                a[x][y] = z;
                a[y][x] = z;
            } else{
                a[x][y] = min(a[x][y], z);
                a[y][x] = a[x][y];
            }
        }
//        printf("\n");
        for(int i = 1; i <= n; i++) a[0][i] = 0;
        memset(dp, 255, sizeof(dp));;
        dp[0][0] = 0;
        l = 0; r = 1; q_vis[1] = 0; q_pos[1] = 0;
        int ans = 2000000000;
        while(l < r){
            l++;
//            printf("%d %d\n", q_vis[l], dp[q_vis[l]][q_pos[l]]);
            int rec_vis = q_vis[l];
            int rec_pos = q_pos[l];
            if(none_empty(rec_vis)){
                ans = min(ans, dp[rec_vis][rec_pos]);
                continue;
            }
            three bit = unpacked(rec_vis);
            for(int i = 1; i <= n; i++){
                if(bit.num[i] == 2) continue;
                if(a[rec_pos][i] == -1) continue;
                bit.num[i]++;
                int x = packed(bit);
                bit.num[i]--;
                if(dp[x][i] == -1 || dp[x][i] > dp[rec_vis][rec_pos] + a[rec_pos][i]){
                    dp[x][i] = dp[rec_vis][rec_pos] + a[rec_pos][i];
                    r++; q_vis[r] = x; q_pos[r] = i;
                }
            }
        }
        if(ans != 2000000000) printf("%d\n", ans); else printf("-1\n");
    }
    return 0;
}

