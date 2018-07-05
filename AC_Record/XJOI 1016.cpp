//XJOI 1016
#include<bits/stdc++.h>
using namespace std;
int n, a[10], b[10];
void work(int x){
    if(n < x){
        for(int i = 1; i <= n; i++) printf("%d ", a[i]);
        printf("\n");
        return;
    }
    for(int i = 1; i <= n; i++)
     if(b[i] == 0){
        b[i] = 1;
        a[x] = i;
        work(x + 1);
        b[i] = 0;
     }
    return;
}
int main(){
    scanf("%d", &n);
    memset(b, 0, sizeof(b));
    work(1);
    return 0;
}