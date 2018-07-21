#include<bits/stdc++.h>
using namespace std;
int n, m;
double ans, p, la, t;
int main(){
    scanf("%d%d", &m, &n);
    ans = 0; la = 0;
    for(int i = 1; i <= m; i++){
        p = pow((double)i / (double)m, n);
        t = p - la;
        ans += t * i;
        la = p;
    }
    printf("%.12f\n", ans);
    return 0;
}

