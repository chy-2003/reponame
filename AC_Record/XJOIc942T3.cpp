#include<bits/stdc++.h>
using namespace std;
int n, m, a[100010], b[100010], l1, l2;
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
    l1 = 1; l2 = 1;
    while(l1 <= n && l2 <= m){
        if(a[l1] < b[l2]){
            printf("%d ", a[l1]);
            l1++;
        } else{
            printf("%d ", b[l2]);
            l2++;
        }
    }
    while(l1 <= n){
        printf("%d ", a[l1]);
        l1++;
    }
    while(l2 <= m){
        printf("%d ", b[l2]);
        l2++;
    }
    return 0;
}