#include<bits/stdc++.h>
using namespace std;
int n;
double b[20];
double orzpsc(int x){
    int cnt = -1;
    double rec = 0;
    for(int i = 0; i < n; i++){
        if((x >> i) & 1){
            cnt *= -1;
            rec += b[i];
        }
    }
    return (double)cnt * (1 / rec);
}
int main(){
    while(scanf("%d", &n) == 1){
        for(int i = 0; i < n; i++) scanf("%lf", &b[i]);
        double ans = 0;
        for(int i = 1; i < (1 << n); i++) {
            ans += orzpsc(i);
//            printf("%d %.lf\n", i, ans);
        }
        printf("%.4lf\n", ans);
    }
    return 0;
}

