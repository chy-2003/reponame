//XJOI 1231
#include<bits/stdc++.h>
using namespace std;
int n, a[1010];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = n; i > 1; i--)
     for(int j = 1; j < i; j++)
      if(a[j] > a[j + 1]) swap(a[j], a[j + 1]);
    for(int i = 1; i <= n; i++) printf("%d ", a[i]);
    return 0;
}