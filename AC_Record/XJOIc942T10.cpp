#include <bits/stdc++.h>
using namespace std;
struct Node{
    long double d, p;
};
long double d1, c, d2, p, maxdis, minnum, minp, ans;
int n, l, id;
Node a[50010];
bool cmp(Node x, Node y){ return x.d < y.d; }
int main(){
    scanf("%Lf%Lf%Lf%Lf%d", &d1, &c, &d2, &p, &n);
    for(int i = 1; i <= n; i++) scanf("%Lf%Lf", &a[i].d, &a[i].p);
    a[0].d = 0; a[0].p = p; a[n + 1].d = d1; a[n + 1].p = 0;
    n += 2;
    sort(a, a + n, cmp);
    maxdis = c * d2;
    for(int i = 1; i < n; i++)
        if(a[i].d - a[i - 1].d > maxdis){
            printf("No solution");
            return 0;
        }
    l = 0;
    minp = 0;
    while(l < n - 1){
        minnum = 2147483647;
        for(int i = l + 1; i < n; i++){
            if(a[i].d > a[l].d + maxdis) break;
            if(a[i].p < minnum){
                minnum = a[i].p;
                id = i;
            }
            if(minnum < a[l].p) break;
        }
        if(minnum < a[l].p){
            ans += ((a[id].d - a[l].d) / d2 - minp) * a[l].p;
            minp = 0;
        } else{
            ans += (c - minp) * a[l].p;
            minp = c - (a[id].d - a[l].d) / d2;
        }
        l = id;
    }
    printf("%.2Lf", ans);
    return 0;
}
/*
275.6 11.9 27.4 2.8 2
102.0 29           
220.0 2.2 
*/