//XJOI 3327
#include<bits/stdc++.h>
using namespace std;
int n, m, f[100010], x, y/*, note[100010]*/;
int get_(int x){
    if(f[x] == x) return x;
    f[x] = get_(f[x]);
    return f[x];
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) f[i] = i;
//  memset(note, 0, sizeof(note));
    for(int i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        x = get_(x); y = get_(y);
        if(x != y){
            f[y] = x;
//          note[x] = 1;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) if(f[i] == i /*&& note[i] != 0*/) ans++;
    printf("%d", ans);
    return 0;
}