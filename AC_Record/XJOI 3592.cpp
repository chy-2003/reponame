//XJOI 3592
#include <bits/stdc++.h>
using namespace std;
int n, a[1010], b[1010], c[1010], t;
void pr(int x){
    if(x == 0) return;
    pr(c[x]);
    printf("%d ", a[x]);
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    n++;
    a[n] = 2147483647;
    for(int i = 1; i <= n; i++){
        b[i] = 1; c[i] = 0;
        for(int j = 1; j < i; j++)
            if(a[j] < a[i]){
                if(b[j] + 1 > b[i]){
                    b[i] = b[j] + 1;
                    c[i] = j;
                } else
                if(b[j] + 1 == b[i] && a[j] < a[c[i]])
                    c[i] = j;
            }
    }
    t = c[n];
    pr(t);
    return 0;
}