//XJOI 3307
#include<bits/stdc++.h>
using namespace std;
int n, x, y, a[2010], b[2010];
int main(){
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &x, &y);
        a[x + y]++;
        b[x - y + 1000]++;
    }
    long long ans = 0;
    for(int i = 0; i <= 2000; i++)
     ans += (a[i] - 1) * a[i] / 2 + (b[i] - 1) * b[i] / 2;
    printf("%d", ans);
    return 0;
}