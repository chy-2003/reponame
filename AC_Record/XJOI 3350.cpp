#include<bits/stdc++.h>
using namespace std;
long long n, a[100010], f[100010][2], x;
int main(){
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &x);
        a[x]++;
    }
    f[1][0] = 0;
    f[1][1] = a[1];
    for(int i = 2; i <= 100000; i++){
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);
        f[i][1] = f[i - 1][0] + a[i] * i;
    }
    printf("%lld\n", max(f[100000][0], f[100000][1]));
    return 0;
}
