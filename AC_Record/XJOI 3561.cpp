//XJOI 3561
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, a[1010], k, t;
    while(scanf("%d", &n) == 1){
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        scanf("%d", &k);
        t = 0;
        for(int i = 0; i < n; i++)
         if(a[i] == k){
            printf("%d\n", i);
            t = 1;
            break;
         }
        if(t == 0) printf("No\n");
    }
    return 0;
}