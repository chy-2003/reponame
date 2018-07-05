//XJOI 1228
#include<bits/stdc++.h>
using namespace std;
int n, l[100], z[100], f[100], rec[100], tot = 0;
void work(int x){
    if(x > n){
        tot++;
        return;
    }
    for(int i = 1; i <= n; i++){
        if(l[i] != 0) continue;
        if(z[i + x] != 0) continue;
        if(f[i - x + n] != 0) continue;
        l[i] = 1; z[i + x] = 1; f[i - x + n] = 1;
        rec[x] = i;
        work(x + 1);
        l[i] = 0; z[i + x] = 0; f[i - x + n] = 0;
    }
    return;
}
int main(){
    memset(l, 0, sizeof(l));
    memset(z, 0, sizeof(z));
    memset(f, 0, sizeof(f));
    scanf("%d", &n);
    work(1);
    printf("%d", tot);
    return 0;
}