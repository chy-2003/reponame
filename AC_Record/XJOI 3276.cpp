//XJOI 3276
#include<bits/stdc++.h>
using namespace std;
int n, f[1010], a[1010];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
     scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++){
        f[i] = 1;
        for(int j = 1; j < i; j++)
         if(a[j] < a[i])
          f[i] = max(f[j] + 1, f[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
     ans = max(ans, f[i]);
    printf("%d", ans);
     
    return 0;
}