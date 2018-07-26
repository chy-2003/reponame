#include<cstdio>
#include<cstring>
int n, m;
double f[1010][1010];
int main(){
    while(~scanf("%d%d", &n, &m)){
        memset(f, 0, sizeof(f));
        for(int i = n; i >= 0; --i)
            for(int j = m; j >= 0; --j){
                if(i == n && j == m) continue;
                f[i][j] = (f[i + 1][j] * (n - i) * j + f[i][j + 1] * i * (m - j) + f[i + 1][j + 1] * (n - i) * (m - j) + n * m) / (n * m - i * j);
            }
        printf("%.4lf\n", f[0][0]);
    }
    return 0;
}

