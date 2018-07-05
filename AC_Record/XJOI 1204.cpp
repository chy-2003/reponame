//XJOI 1204
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, a[1010];
    memset(a, 0, sizeof(a));
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int num;
    for(int i = 1; i <= n; i++){
        num = 0;
        for(int j = i; j <= n; j++)
         if(a[i] == a[j]) num++;
        if(num > n / 2) printf("%d", a[i]);
    }
    return 0;
}