//XJOI 3334
#include<bits/stdc++.h>
using namespace std;
int n, fa[1010], x, y, rec[1010];
int main(){
    scanf("%d", &n);
    for(int i = 2; i <= n; i++) scanf("%d", &fa[i]);
    scanf("%d%d", &x, &y);
    memset(rec, 0, sizeof(rec));
    for(;x; x = fa[x]){
        rec[x] = 1;
    }
    for(;y;y = fa[y]){
        if(rec[y]){
            printf("%d", y);
            break;
        }
    }
    return 0;
}