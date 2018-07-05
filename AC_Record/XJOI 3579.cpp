#include<bits/stdc++.h>
using namespace std;
int n, k;
double a[10010], l, r, mid;
int pan(double x){
    int cnt = 0;
    for(int i = 1; i <= n; i++)
     cnt += (int)floor(a[i] / x);
    return cnt;
}
int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)
     scanf("%lf", &a[i]);
    l = 0; r = 0;
    for(int i = 1; i <= n; i++) r = max(r, a[i]);
    while(r - l > 0.0001){
        mid = (l + r) / 2;
        if(pan(mid) >= k) l = mid; else r = mid;
    }
    printf("%.2lf", floor(r*100)/100);
    return 0;
}
