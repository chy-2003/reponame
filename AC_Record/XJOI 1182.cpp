//XJOI 1182
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, a[2010];
    scanf("%ds", &n);
    memset(a, 0, sizeof(a));
    for(int i = 2; i <= n; i++){
        if(a[i]) continue;
        for(int j = i * 2; j <= n; j += i)
         a[j] = 1;
    }
    for(int i = 2; i <= n; i++)
     if(!a[i]) printf("%d ", i);
    return 0;
}