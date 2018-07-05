//XJOI 1017
#include<bits/stdc++.h>
using namespace std;
int n, a[20], m;
void work(int x, int y){
    if(x > m){
        for(int i = 1; i <= m; i++) printf("%d ", a[i]);
        printf("\n");
        return;
    }
    for(int i = y + 1; i <= n - (m - x); i++){
        a[x] = i;
        work(x + 1, i);
    }
    return;
}
int main(){
    scanf("%d%d", &n, &m);
    work(1, 0);
    return 0;
}