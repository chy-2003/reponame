//XJOI 3274
#include <bits/stdc++.h>
using namespace std;
int n, a[110][110];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            scanf("%d", &a[i][j]);
    for(int i = n - 1; i >= 1; i--)
        for(int j = 1; j <= i; j++)
            a[i][j] = a[i][j] + max(a[i + 1][j], a[i + 1][j + 1]);
    printf("%d", a[1][1]);
    return 0;
}