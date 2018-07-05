//XJOI 1202
#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int m, aa, b, c;
    scanf("%d", &m);
    for(int i = 1; i <= m; i++){
        scanf("%d%d%d", &aa, &b, &c);
        for(int j = aa; j <= b; j++)
         a[j] += c;
    }
    for(int i = 1; i <= n; i++) printf("%d ", a[i]);
    return 0;
}