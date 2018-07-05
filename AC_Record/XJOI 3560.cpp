//XJOI 3560
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, t, a[1010];
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &t);
        for(int j = 1; j <= t; j++) scanf("%d", &a[j]);
        for(int j = t; j >= 1; j--) printf("%d ", a[j]);
        printf("\n");
    }
    return 0;
}