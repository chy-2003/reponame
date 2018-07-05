//XJOI 1119
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, a[30];
    a[1] = 0;
    a[2] = 1;
    a[3] = 1;
    scanf("%d", &n);
    for(int i = 4; i <= n; i++) a[i] = a[i - 3] + 2 * a[i - 2] + a[i - 1];
    printf("%d", a[n]);
    return 0;
}