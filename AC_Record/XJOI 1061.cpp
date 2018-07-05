//XJOI 1061
#includebitsstdc++.h
using namespace std;
long long s, t, n, m, ma[1010][1010], x, y, z, dis[1010], fa[1010], vis[1010];
bool cmp(int x, int y){
    return (x == -1)  (x  y);
}
void print__(long long x){
    if(x != s) print__(fa[x]);
    printf(%lld , x);
    return;
}
int main(){
    scanf(%lld%lld, &s, &t);
    scanf(%lld%lld, &n, &m);
    memset(ma, 255, sizeof(ma));
    for(int i = 1; i = m; i++){
        scanf(%lld%lld%lld, &x, &y, &z);
        if(cmp(ma[x][y], z)){
            ma[x][y] = z;
            ma[y][x] = z;
        }
    }
    memset(dis, 255, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[s] = 0;
    long long minnum, id;
    for(int i = 1; i  n; i++){
        minnum = -1;
        for(int j = 1; j = n; j++){
            if(vis[j]) continue;
            if(dis[j] == -1) continue;
            if(cmp(minnum, dis[j])){
                minnum = dis[j];
                id = j;
            }
        }
        vis[id] = 1;
        for(int j = 1; j = n; j++){
            if(vis[j]) continue;
            if(ma[id][j] == -1) continue;
            if(cmp(dis[j], dis[id] + ma[id][j])){
                dis[j] = dis[id] + ma[id][j];
                fa[j] = id;
            }
        }
    }
    printf(%lldn, dis[t]);
    print__(t);
    return 0;
}