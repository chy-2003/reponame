//XJOI 3333
#include<bits/stdc++.h>
using namespace std;
int n, cnt[1010], fa[1010];
int main(){
    scanf("%d", &n);
    for(int i = 2; i <= n; i++) scanf("%d", &fa[i]);
    fa[1] = 0;
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1;  i <= n; i++){
        int x = i;
        while(x){
            cnt[x]++;
            x = fa[x];
        }
    }
    for(int i = 1; i <= n; i++) printf("%d ", cnt[i]);
    return 0;
}