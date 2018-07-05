//XJOI 3304
#include<bits/stdc++.h>
using namespace std;
int n, a[110];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    printf("%d ", a[n]);
    for(int i = 2; i < n; i++) printf("%d ", a[i]);
    printf("%d\n", a[1]);
    return 0;
}