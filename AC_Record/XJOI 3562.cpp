//XJOI 3562
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, a[1010], k, t;
    while(scanf("%d", &n) == 1){
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        scanf("%d", &k);
        t = 0;
        for(int i = 1; i <= n; i++)
         if(a[i] == k && t == 0){
            t++;
         } else printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}