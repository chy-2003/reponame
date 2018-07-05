//XJOI 1643
#include<bits/stdc++.h>
using namespace std;
int n, m, a[110], b[100010];
double c[100010], f[110];
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= m; i++) scanf("%d%lf", &b[i], &c[i]);
    for(int i = 1; i <= n; i++) f[i] = 10000010;
    f[0] = 0;
    for(int i = 1; i <= m; i++)
     for(int j = n; j >= 1; j--)
      if(b[i] == a[j])
       f[j] = min(f[j], f[j - 1] + c[i]);
    if(f[n] < 10000010) printf("%.2lf", f[n]); else printf("Impossible");
    return 0;
}