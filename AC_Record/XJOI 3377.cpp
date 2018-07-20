#include<bits/stdc++.h>
using namespace std;
struct status{
    int first, second;
    status(int first_ = 0, int second_ = 0) { first = first_; second = second_; return; }
};
int a[30], b[30], n;
int f[30][30][30][30];
status rec[30][30][30][30];
status work(int l1, int r1, int l2, int r2){
    if(f[l1][r1][l2][r2] != -1) return rec[l1][r1][l2][r2];
    status t = status(0, 0);
    if(l1 == r1 && l2 > r2){
        t.first = a[l1];
        t.second = 0;
        rec[l1][r1][l2][r2] = t;
        f[l1][r1][l2][r2] = 1;
        return t;
    }
    if(l1 > r1 && l2 == r2){
        t.first = b[l2];
        t.second = 0;
        rec[l1][r1][l2][r2] = t;
        f[l1][r1][l2][r2] = 1;
        return t;
    }
    status tt = status(0, 0);
    if(l1 <= r1){
        tt = work(l1 + 1, r1, l2, r2);
        if(tt.second + a[l1] > t.first) t.first = tt.second + a[l1], t.second = tt.first;
        tt = work(l1, r1 - 1, l2, r2);
        if(tt.second + a[r1] > t.first) t.first = tt.second + a[r1], t.second = tt.first;
    }
    if(l2 <= r2){
        tt = work(l1, r1, l2 + 1, r2);
        if(tt.second + b[l2] > t.first) t.first = tt.second + b[l2], t.second = tt.first;
        tt = work(l1, r1, l2, r2 - 1);
        if(tt.second + b[r2] > t.first) t.first = tt.second + b[r2], t.second = tt.first;
    }
    rec[l1][r1][l2][r2] = t;
    f[l1][r1][l2][r2] = 1;
    return t;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
    memset(f, 255, sizeof(f));
    status ans = work(1, n, 1, n);
    printf("%d\n", ans.first);
    return 0;
}

