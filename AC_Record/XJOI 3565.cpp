//XJOI 3565
#include<bits/stdc++.h>
using namespace std;
int n, a[30], b[30], maxnum, l2, ans, t;
int main(){
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for(int i = 1; i <= n; i++){
        scanf("%d", &t);
        a[t]++;
        if(b[t] == 0) b[t] = i;
    }
    maxnum = 0;
    l2 = n + 1;
    for(int i = 0; i < 20; i++)
     if(a[i] > maxnum || (a[i] == maxnum && b[i] < l2)){
        maxnum = a[i];
        ans = i;
        l2 = b[i];
     }
    printf("%d", ans);
    return 0;
}