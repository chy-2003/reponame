//XJOI 1193
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, a, b, c, t, bo, k;
    while(scanf("%d", &n) == 1){
        a = 0;
        b = 0;
        c = 0;
        bo = 1;
        for(int i = 1; i <= n; i++){
            scanf("%d", &t);
            if(!bo) continue;
            if(t == 25) a++; else if(t == 50) b++; else c++;
            t -= 25;
            k = min(c, t / 100);
            t -= k * 100;
            c -= k;
            k = min(b, t / 50);
            t -= k * 50;
            b -= k;
            k = min(a, t / 25);
            t -= k * 25;
            a -= k;
            if(t) bo = 0;
        }
        if(bo) printf("YES\n"); else printf("NO\n");
    }
    return 0;
}