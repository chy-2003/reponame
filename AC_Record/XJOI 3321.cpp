//XJOI 3321
#include<bits/stdc++.h>
using namespace std;
int n, a[2][1010], ans, b;
int main(){
    scanf("%d", &n);
    while(n){
        for(int i = 1; i <= n; i++)
         scanf("%d", &a[0][i]);
        ans = 0;
        while(1){
            b = 1;
            for(int i = 2; i <= n; i++)
             if(a[ans % 2][i] != a[ans % 2][i - 1]){
                b = 0;
                break;
             }
            if(b) break;
            ans++;
            for(int i = 2; i <= n; i++)
             a[ans % 2][i] = a[(ans - 1) % 2][i] / 2 + a[(ans - 1) % 2][i - 1] / 2;
            a[ans % 2][1] = a[(ans - 1) % 2][1] / 2 + a[(ans - 1) % 2][n] / 2;
            for(int i = 1; i <= n; i++) if(a[ans % 2][i] % 2 == 1) a[ans % 2][i]++;
        }
        printf("%d %d\n", ans, a[ans % 2][1]);
        scanf("%d", &n);
    }
    return 0;
}