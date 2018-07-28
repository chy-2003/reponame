#include <bits/stdc++.h>
using namespace std;
int n;
long double l, r, a[20];
long double mid1, mid2, mid1_val, mid2_val;
long double length;
long double get_val(long double x){
    long double power = 1, ans = 0;
    for(int i = n + 1; i >= 1; i--){
//        printf("%.5Lf ", power * a[i]);
        ans += power * a[i];
        power *= x;
    }
    return ans;
}
int main(){
    scanf("%d%Lf%Lf", &n, &l, &r);
    for(int i = 1; i <= n + 1; i++) scanf("%Lf", &a[i]);
    for(int i = 1; i <= 10000; i++){
        length = r - l;
        length /= 3;
        mid1 = l + length;
        mid2 = mid1 + length;
        mid1_val = get_val(mid1); //printf("\n");
        mid2_val = get_val(mid2); //printf("\n");
        if(mid1_val < mid2_val) l = mid1; else r = mid2;
//        printf("%.5Lf %.5Lf, %.5Lf %.5Lf, %.5Lf %.5Lf\n", mid1, mid2, mid1_val, mid2_val, l, r);
    }
    printf("%.5Lf\n", l);
    return 0;
}

