//XJOI 1201
#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
    memset(a, 0, sizeof(0));
    int n = 1000000;
    for(int i = 2; i <= n; i++){
        if(a[i]) continue;
        for(int j = i + i; j <= n; j += i)
         if(!a[j]) a[j] = 1;
    }
    for(int i = 2; i <= n; i++)
     if(a[i]) a[i] = a[i - 1]; else a[i] = a[i - 1] + 1;
    scanf("%d", &n);
    int t;
    for(int i = 1; i <= n; i++){
        scanf("%d", &t);
        printf("%d\n", a[t]);
    }
    return 0;
}