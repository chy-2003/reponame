#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN = 200010, INF = 2000000000, MAXDEEP = 20;
int n, P[MAXN], L[MAXN], R[MAXN], U[MAXN][MAXDEEP], S[MAXN][MAXDEEP];
int m, x, y, ans;

int tree[MAXN];
    
void up (int x, int v) {
    while(x <= n) {
        tree[x] = max(tree[x], v);
        x += x & -x;
    }
}

int get (int x) {
    int ans = 0;
    while(x > 0) {
        ans = max(ans, tree[x]);
        x -= x & -x;
    }
    return ans;
}

int find(int x){
    int l = 1, r = n + 1, mid;
    while(l < r){
        mid = (l + r) / 2;
        if(P[mid] < x) l = mid + 1; else r = mid;
    }
    return l;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d%d", &P[i], &L[i]);
    P[n + 1] = INF;
    R[n] = P[n] + L[n];
    for(int i = n - 1; i >= 1; i--){
        R[i] = max(P[i] + L[i], get(find(P[i] + L[i]) - 1));
        up(i, R[i]);
    }
    R[n + 1] = INF;
//    for(int i = 1; i <= n; i++) printf("%d ", R[i]); printf("\n");
    for(int i = 1; i <= n; i++) U[i][0] = find(R[i]);
    for(int i = 1; i < MAXDEEP; i++)
        for(int j = 1; j <= n; j++)
            U[j][i] = U[U[j][i - 1]][i - 1];
//    printf("\n");
//    for(int i = 0; i <= 2; i++){
//        for(int j = 1; j <= n; j++) printf("%d ", U[j][i]);
//        printf("\n");
//    }
    for(int i = 1; i <= n; i++) S[i][0] = P[U[i][0]] - R[i];
    for(int i = 1; i < MAXDEEP; i++)
        for(int j = 1; j <= n; j++)
            S[j][i] = S[j][i - 1] + S[U[j][i - 1]][i - 1];
//    printf("\n");
//    for(int i = 0; i <= 2; i++){
//        for(int j = 1; j <= n; j++) printf("%d ", S[j][i]);
//        printf("\n");
//    }
    scanf("%d", &m);
    for(int i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        if(R[x] >= P[y]){
            printf("0\n");
            continue;
        }
        ans = 0;
        for(int j = MAXDEEP - 1; j >= 0; j--)
            if(U[x][j] != 0 && R[U[x][j]] < P[y]){
                ans += S[x][j];
                x = U[x][j];
            }
        ans += S[x][0];
        printf("%d\n", ans);
    }
    return 0;
}
