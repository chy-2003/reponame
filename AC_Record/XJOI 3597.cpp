//XJOI 3597
#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007;
long long f[1010][1010], n, k;
int main(){
    memset(f, 0, sizeof(f));
    scanf("%lld%lld", &n, &k);
    f[1][1] = 1;
    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= i; j++)
            f[i][j] = ((f[i - 1][j] * (i - 1)) % M + f[i - 1][j - 1]) % M;
    printf("%lld", f[n][k]); 
    return 0;
}