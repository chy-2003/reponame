#include<bits/stdc++.h>
using namespace std;
int n, t;
double p;
double f[2010][2010];
int main(){
    scanf("%d%lf%d", &n, &p, &t);
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for(int i = 0; i < t; i++){
        for(int j = 0; j < n; j++){
            f[i + 1][j] += f[i][j] * (1.0 - p);
            f[i + 1][j + 1] += f[i][j] * p;
        }
        f[i + 1][n] += f[i][n];
    }
    double ans = 0;
    for(int i = 0; i <= n; i++) ans += f[t][i] * i;
    printf("%.7lf\n", ans);
    return 0;
}


