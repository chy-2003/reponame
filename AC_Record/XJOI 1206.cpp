//XJOI 1206
#include<bits/stdc++.h>
using namespace std;
int n, m, a[5000010], b[5000010];
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
    int i = 1, j = 1;
    while(i <= n && j <= m){
        if(a[i] <= b[j]){
            printf("%d ", a[i]);
            i++;
        } else {
            printf("%d ", b[j]);
            j++;
        }
    }
    while(i <= n){
        printf("%d ", a[i]);
        i++;
    }
    while(j <= m){
        printf("%d ", b[j]);
        j++;
    }
    return 0;
}