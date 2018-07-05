//XJOI 3331
#include <bits/stdc++.h>
using namespace std;
int n, m;
int ll = 0, first[5010], next[16010], val[16010], x, y;
void add(int x, int y){
    ll++;
    next[ll] = first[x];
    first[x] = ll;
    val[ll] = y;
    return;
}
int l, r, q[5010], dis[5010], st, en;
int main(){
    scanf("%d%d", &n, &m);
    memset(first, 0, sizeof(first));
    for(int i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        add(x, y); add(y, x);
    }
    memset(dis, 255, sizeof(dis));
    scanf("%d%d", &st, &en);
    dis[st] = 0;
    l = 0; r = 1; q[1] = st;
    while(l < r && dis[en] == -1){
        l++;
        for(int i = first[q[l]]; i; i = next[i]){
            if(dis[val[i]] != -1) continue;
            r++;
            q[r] = val[i];
            dis[val[i]] = dis[q[l]] + 1;
            if(val[i] == en) break;
        }
    }
    printf("%d\n", dis[en]);
    return 0;
}