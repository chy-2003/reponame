//XJOI 1236
#include<bits/stdc++.h>
using namespace std;
int n, l, r, q[1000010];
int main(){
    scanf("%d", &n);
    r = 1; l = 0; q[1] = 1;
    while(l < r){
        l++;
        if(q[l] * 10 <= n){
            r++;
            q[r] = q[l] * 10;
        }
        if(q[l] * 10 + 1 <= n){
            r++;
            q[r] = q[l] * 10 + 1;
        }
    }
    printf("%d", r);
    return 0;
}