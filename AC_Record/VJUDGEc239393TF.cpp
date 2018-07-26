#include<cstdio>
#include<cstring>
using namespace std;
long long n, m, f[1 << 12], g[1 << 12];
int main(){
    scanf("%lld%lld", &n, &m);
    while(!((n == 0) && (m == 0))){
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        f[(1 << m) - 1] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                for(int k = 0; k <= (1 << m) - 1; k++){
                    if(f[k] == 0) continue;
                    if(((k >> (j - 1)) & 1) == 0){
                        g[k | (1 << (j - 1))] += f[k];
                        continue;
                    }
                    g[k - (1 << (j - 1))] += f[k];
                    if(j > 1 && ((k >> (j - 2)) & 1) == 0) g[k | (1 << (j - 1)) | (1 << (j - 2))] += f[k];
                }
                for(int k = 0; k <= (1 << m) - 1; k++) f[k] = g[k];
                memset(g, 0, sizeof(g));
            }
        }
        printf("%lld\n", f[(1 << m) - 1]);
        scanf("%lld%lld", &n, &m);
    }
    return 0;
}

