#include<bits/stdc++.h>
using namespace std;
long long n, t[10010], x, c;
int main(){
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &x);
        scanf("%lld", &c);
        scanf("%lld", &x);
        while(x){
            t[i] = max(t[i], t[x]);
            scanf("%lld", &x);
        }
        t[i] += c;
    }
    x = 0;
    for(int i = 1; i <= n; i++) x = max(x, t[i]);
    printf("%lld", x);
    return 0;
}
