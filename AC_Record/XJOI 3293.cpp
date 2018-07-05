//XJOI 3293
#include<bits/stdc++.h>
using namespace std;
int n, a[110];
int gcd(int x, int y){
    int m = x % y;
    while(m){
        x = y; y = m; m = x % y;
    }
    return y;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int ans = a[1];
    for(int i = 2; i <= n; i++) ans = gcd(ans, a[i]);
    printf("%d", ans * n);
    return 0;
}