//XJOI 1207
#include<bits/stdc++.h>
using namespace std;
int n, ans = 0, a[1010];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int l = 1, r = n;
    while(l <= r){
        if(r - l + 1 == 1){
            ans += a[r];
            break;
        }
        if(r - l + 1 == 2){
            ans += a[r];
            break;
        }
        if(r - l + 1 == 3){
            ans += a[l] + a[l + 1] + a[r];
            break;
        }
        if(2 * a[l + 1] >= a[l] + a[r - 1]){
            ans += 2 * a[l] + a[r] + a[r - 1];
            r -= 2;
        } else{
            ans += a[l + 1] + a[l] + a[r] + a[l + 1];
            r -= 2;
        }
    }
    printf("%d", ans);
    return 0;
}