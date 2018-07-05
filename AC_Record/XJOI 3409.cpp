//XJOI 3409
#include<bits/stdc++.h>
using namespace std;
int n, k, a[40], t, kk;
int ans[110];
int main(){
    scanf("%d%d", &n, &k);
    if(k == 0){
        printf("1");
        return 0;
    }
    if(k > n){
        printf("0");
        return 0;
    }
    memset(a, 0, sizeof(a));
    for(int i = n; i > n - k; i--){
        t = i;
        kk = 1;
        while(t > 1){
            kk++;
            while(t % kk == 0){
                t /= kk;
                a[kk] += 2;
            }
        }
    } //printf("*");
    for(int i = k; i > 1; i--){
        t = i;
        kk = 1;
        while(t > 1){
            kk++;
            while(t % kk == 0){
                t /= kk;
                a[kk]--;
            }
        }
    } //printf("*");
    memset(ans, 0, sizeof(ans));
    ans[0] = 1;
    ans[1] = 1;
    for(int i = 1; i <= n; i++)
     for(int j = 1; j <= a[i]; j++){
        for(int kk = 1; kk <= ans[0]; kk++)
         ans[kk] *= i;
        for(int kk = 1; kk <= ans[0]; kk++){
            ans[kk + 1] += ans[kk] / 10;
            ans[kk] %= 10;
         }
        while(ans[ans[0] + 1] > 0){
            ans[0]++;
            ans[ans[0] + 1] += ans[ans[0]] / 10;
            ans[ans[0]] %= 10;
        }
        //printf("%d\n", ans[0]);
     } //printf("*");
    for(int i = ans[0]; i > 0; i--)
     printf("%d", ans[i]);
    return 0;
}