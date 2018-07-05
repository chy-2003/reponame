//XJOI 1197
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    if(k < n){
        printf("0");
        return 0;
    }
    if(m * 3 < n){
        printf("%d", 3 + (k - n) / m);
    } else{
        printf("%d", 3 * (k / n) + (k % n) / m);
    }
    return 0;
}