//XJOI 1205
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k, m, a[110];
    memset(a, 0, sizeof(a));
    scanf("%d%d%d0", &n, &k, &m);
    k--;
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= m; j++){
            k++;
            k %= n;
            while(a[k]){
                k++;
                k %= n;
            }
        }
        a[k] = 1;
    }
    k++;
    k %= n;
    while(a[k]){
        k++;
        k %= n;
    }
    printf("%d", k);
    return 0;
}