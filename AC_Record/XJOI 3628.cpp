#include<bits/stdc++.h>
using namespace std;
int n, m;
struct Edge{
    int x, y, val;
    Edge(int x_ = 0, int y_ = 0, int val_ = 0) { x = x_; y = y_; val = val_; return; }
};
Edge edge[100010];
int ans1, ans2;
int f[100010];
int l;
bool cmp1(Edge x, Edge y){
    return x.val > y.val;
}
bool cmp2(Edge y, Edge x){
    return x.val > y.val;
}
int get_(int x){
    if(f[x] == x) return x;
    f[x] = get_(f[x]);
    return f[x];
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        edge[i] = Edge(x, y, z);
    }
    sort(edge + 1, edge + m + 1, cmp1);
    for(int i = 1; i <= n; i++) f[i] = i;
    l = 1;
    ans1 = 0;
    for(int i = 1; i < n; i++){
        int xx = get_(edge[l].x);
        int yy = get_(edge[l].y);
        while(xx == yy){
            l++;
            xx = get_(edge[l].x);
            yy = get_(edge[l].y);
        }
        f[yy] = xx;
        if(edge[l].val == 0) ans1++;
    }
    sort(edge + 1, edge + m + 1, cmp2);
    for(int i = 1; i <= n; i++) f[i] = i;
    l = 1;
    ans2 = 0;
    for(int i = 1; i < n; i++){
        int xx = get_(edge[l].x);
        int yy = get_(edge[l].y);
        while(xx == yy){
            l++;
            xx = get_(edge[l].x);
            yy = get_(edge[l].y);
        }
        f[yy] = xx;
        if(edge[l].val == 0) ans2++;
    }
    int a1 = 1, a2 = 2;
    if(ans1 <= a1 && a1 <= ans2){
        printf("Yes");
        return 0;
    }
    while(a2 <= ans2){
        if(ans1 <= a2 && a2 <= ans2){
            printf("Yes");
            return 0;
        }
        a1 += a2;
        swap(a1, a2);
    }
    printf("No");
    return 0;
}

