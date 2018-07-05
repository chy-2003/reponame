//XJOI 1160
#include<bits/stdc++.h>
using namespace std;
int n, a[1010], minnum, id;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i < n; i++){
        minnum = 2147483647;
        for(int j = i; j <= n; j++)
         if(a[j] < minnum){
            minnum = a[j];
            id = j;
         }
        swap(a[i], a[id]);
    }
    for(int i = 1; i <= n; i++) printf("%d ", a[i]);
    return 0;
}

版权所有