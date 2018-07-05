//XJOI 1178
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    if(k == 0 || k == n){
        printf("0 ");
    } else printf("1 ");
    printf("%d\n", min(n - k, k * 2));
    return 0;
}