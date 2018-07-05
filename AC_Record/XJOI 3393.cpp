//XJOI 3393
#include<bits/stdc++.h>
using namespace std;
int n, x, a[100010];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &x);
        a[i] = 0;
        while(x){
            if(x % 2 == 1) a[i]++;
            x /= 2;
        }
    }
    sort(a + 1, a + n + 1);
    int la = 1, ans = 0;
    for(int i = 2; i <= n; i++)
     if(a[i] != a[i - 1]){
        la = i;
     } else ans += i - la;
    printf("%d", ans);
    return 0;
}