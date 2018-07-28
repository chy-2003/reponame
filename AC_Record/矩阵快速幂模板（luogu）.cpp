#include <bits/stdc++.h>
#define LL long long
using namespace std;
const LL mod = 1000000007;
LL n, k;
struct Matrix{
    LL a[110][110];
};
Matrix one, ans;
Matrix multiply(Matrix a, Matrix b){
    Matrix ans;
    memset(ans.a, 0, sizeof(ans.a));
    for(LL i = 1; i <= n; i++)
        for(LL j = 1; j <= n; j++)
            for(LL k = 1; k <= n; k++)
                ans.a[i][j] = (ans.a[i][j] + a.a[i][k] * b.a[k][j] % mod) % mod;
    return ans;
}
Matrix power(LL x){
    if(x == 1) return one;
    Matrix t = power(x / 2);
    t = multiply(t, t);
    if(x % 2 == 1) t = multiply(one, t);
    return t;
}
int main(){
    scanf("%lld%lld", &n, &k);
    memset(one.a, 0, sizeof(one.a));
    memset(ans.a, 0, sizeof(ans.a));
    for(LL i = 1; i <= n; i++)
        for(LL j = 1; j <= n; j++)
            scanf("%lld", &one.a[i][j]);
    ans = power(k);
    for(LL i = 1; i <= n; i++){
        for(LL j = 1; j <= n; j++) printf("%lld ", ans.a[i][j]);
        printf("\n");
    }
    return 0;
}

