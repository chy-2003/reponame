//XJOI 1131
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, a[210];
    memset(a, 0, sizeof(a));
    a[0] = 1;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
     a[i] += a[i - 1];
    for(int i = 2; i <= n; i++)
     a[i] += a[i - 2];
    for(int i = 5; i <= n; i++)
     a[i] += a[i - 5];
    printf("%d", a[n]);
    return 0;
}