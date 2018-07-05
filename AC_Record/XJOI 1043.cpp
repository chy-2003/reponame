//XJOI 1043
#include<bits/stdc++.h>
using namespace std;
int n, a[110], b[110];
int x, t, la;
int main(){
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for(int i = 1; i <= n; i++){
        scanf("%d", &x);
        if(x == 0) continue;
        scanf("%d", &t);
        a[i] = t;
        la = t;
        x--;
        for(int j = 1; j <= x; j++){
            scanf("%d", &t);
            b[la] = t;
            la = t;
        }
    }
    printf("%d\n", n);
    for(int i = 1; i <= n; i++) printf("%d %d\n", a[i], b[i]);
    return 0;
}