#include<bits/stdc++.h>
using namespace std;
const long long MAXN = 210, MAXM = 210;
long long n, m, a[MAXN][MAXM], s[MAXN][MAXM], cnt, ans;
int main(){
    scanf("%lld%lld", &n, &m);
    for(long long i = 1; i <= n; i++)
        for(long long j = 1; j <= m; j++)
            scanf("%lld", &a[i][j]);
    for(long long i = 1; i <= n; i++)
        for(long long j = 1; j <= m; j++)
            s[i][j] = s[i][j - 1] + a[i][j];
    ans = 0;        
    for(long long i = 1; i < m; i++)
        for(long long j = i + 1; j <= m; j++){
            cnt = 0;
            for(long long k = 1; k <= n; k++){
                if(cnt < 0) cnt = 0;
                cnt += s[k][j] - s[k][i - 1];
                ans = max(ans, cnt);
            }
        }
    printf("%lld", ans);
    return 0;
}
